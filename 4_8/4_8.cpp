
#include <std_lib_facilities.h>

int main()
{
    int cur_cell_num = 0;
    int cur_cell_grains_num=1,
        all_prev_grains_num{},
        required_grains_num;
    cout << "Enter required grains number:\n";
    while (cin >> required_grains_num)
    {
        for (cur_cell_num; cur_cell_grains_num + all_prev_grains_num < required_grains_num; cur_cell_num++)
        {
            if (cur_cell_num > 0)
            {
                all_prev_grains_num += cur_cell_grains_num;
                cur_cell_grains_num *= 2;
            }
            cout << "Current cell number is " << cur_cell_num + 1 << endl;
            if (cur_cell_grains_num + all_prev_grains_num <= required_grains_num)
                cout << "Number of grains in current cell is " << cur_cell_grains_num << endl;
            else cout << "Number of grains in current cell is " << required_grains_num - all_prev_grains_num << endl;
            cout << "Number of grains in all previos cells is " << all_prev_grains_num << endl << endl;
        }
        cur_cell_num = (cur_cell_num > 0) ? cur_cell_num : 1;
        cout << "To store " << required_grains_num << " grains king needs to use " << cur_cell_num << " cells." << endl << endl;
        cur_cell_num = all_prev_grains_num = 0;
        cur_cell_grains_num = 1;
        cout << "Enter required grains number:\n";
    }

}
