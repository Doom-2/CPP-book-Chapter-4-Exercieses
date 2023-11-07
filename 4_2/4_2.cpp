
#include <std_lib_facilities.h>

int main()
{
    vector<double> temps; // temperatures
    cout << "Enter a set of temperatures" << endl;
    for (double temp; cin >> temp; ) // read into temp
        temps.push_back(temp); // put temp into vector

    double sum = 0, median;
    for (double x : temps) sum += x;
    cout << "Sum is " << sum << endl;
    cout << "Average temperature: " << sum / temps.size() << '\n';
    // compute median temperature:
    sort(temps); // sort temperatures
    size_t size = temps.size();
    if (size == 0) median = 0;
    else if (size % 2 != 0) median = temps[size / 2];
    else median = (temps[size / 2 - 1] + temps[size / 2]) / 2;
    cout << "Median temperature: " << median << '\n';
}
