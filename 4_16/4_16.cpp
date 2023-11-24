
#include <std_lib_facilities.h>


int cin_positive_int()
{
    int val;
    do {
        try {
            if (!(cin >> val)) throw 1;
            if (cin.good() && val <= 0 && cin.peek() == '\n') throw 2;
            if (cin.peek() != '\n') throw 3;
        }
        catch (int i) {
            switch (i)
            {
            case 1:
            case 3:
                cerr << "Invalid input! Only integer is allowed.\n" << ">";
                cin.clear();
                break;
            case 2:
                cerr << "Invalid input! An integer must be a positive.\n" << ">";
                cin.clear();
                break;
            default:
                break;
            }
            while (cin.get() != '\n');
            continue;
        }
        break;
    } while (true);
    return val;
}

int main()
{
    vector<int> nums;
    int size, num;
    cout << "Enter vector size" << endl;
    size = cin_positive_int();
    cout << "Enter vector elements. Press Enter after entering each one." << endl;
    int i = 0;
    // Fill the vector with positive integers
    while (i < size)
    {
        num = cin_positive_int();
        nums.push_back(num);
        i++;
    }
    sort(nums);
    int mode = 1;
    /* Iterate over the vector and accumulate repeatments if current value equals to next one.
       If neighboring values are not equal, reset repeatment value to 1 and continue the loop.
       Along the way store and update max repeatments */
    for (int i = 0, cur_reps = 1; i < nums.size(); i++)
    {
        if (i < nums.size()-1 && nums[i] == nums[i + 1]) {
            cur_reps++; continue; }
        if (cur_reps > mode) mode = cur_reps;
        cur_reps = 1;
    }
    cout << "Mode of the current set is " << mode << endl;
}
