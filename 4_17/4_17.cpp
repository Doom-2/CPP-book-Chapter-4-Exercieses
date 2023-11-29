
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
    while (cin.get() != '\n');
    return val;
}


int main()
{
    vector <string> strings;
    int size, mode = 1;
    string str;
    cout << "Enter vector size" << endl;
    size = cin_positive_int();
    cout << "Enter vector elements. Press Enter after entering each one." << endl;
    int i = 0;

    // Fill the vector with strings
    while (i < size)
    {
        getline(cin, str);
        strings.push_back(str);
        i++;
    }
    // Sort strings vector by length
    sort(strings.begin(), strings.end(), []
    (const string& first, const string& second) {
            return first.size() < second.size();
        });
    cout << endl << "Strings by ascending length" << endl;
    cout << setw(20) << left << "STRING" << right << setw(4) << "LENGTH" << endl;
    for (string str : strings)
        cout << setw(20) << left << str << right << setw(4) << str.size() << endl;

    /* Iterate over the vector and accumulate repeatments if current value equals to next one.
       If neighboring values are not equal, reset repeatment value to 1 and continue the loop.
       Along the way store and update max repeatments */
    for (int i = 0, cur_reps = 1; i < strings.size(); i++)
    {
        if (i < strings.size() - 1 && strings[i].size() == strings[i + 1].size()) {
            cur_reps++; continue;
        }
        if (cur_reps > mode) mode = cur_reps;
        cur_reps = 1;
    }
    cout << endl << setw(35) << left << "Min of the current sequence is " << right << setw(4) << strings[0].size() << endl;
    cout << setw(35) << left << "Max of the current sequence is " << right << setw(4) << strings.back().size() << endl;
    cout << setw(35) << left << "Mode of the current sequence is " << right << setw(4) << mode << endl;
}
