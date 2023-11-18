
#include <std_lib_facilities.h>

int main()
{
    int cur_cell_num = 1;
    int cur_cell_grains_num = 1,
        all_prev_grains_num{};
    double cur_cell_grains_num_d = double(cur_cell_grains_num);
    double all_prev_grains_num_d = double(all_prev_grains_num);

    // Calculate cells needed to store 2147483647 (INT_MAX) grains
    for (cur_cell_num; cur_cell_grains_num + all_prev_grains_num < INT_MAX; cur_cell_num++)
    {
        all_prev_grains_num = (cur_cell_num > 1) ? all_prev_grains_num + cur_cell_grains_num : 0;
        cur_cell_grains_num = (all_prev_grains_num > 0) ? cur_cell_grains_num * 2 : 1;
    }
    cout << "To store " << INT_MAX << " (MAX INT) grains king needs to use " << cur_cell_num - 1 << " cells." << endl << endl;
    
    // Calculate cells needed to store 1.7976931348623158e+308 (DBL_MAX) grains
    for (cur_cell_num=1; cur_cell_grains_num_d + all_prev_grains_num_d < DBL_MAX; cur_cell_num++)
    {
        all_prev_grains_num_d = (cur_cell_num > 1) ? all_prev_grains_num_d + cur_cell_grains_num_d : 0;
        cur_cell_grains_num_d = (all_prev_grains_num_d > 0) ? cur_cell_grains_num_d * 2 : 1;
    }
    cout << "To store " << DBL_MAX << " (MAX DOUBLE) grains king needs to use " << cur_cell_num - 1 << " cells." << endl << endl;
}
