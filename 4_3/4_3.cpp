
#include <std_lib_facilities.h>

int main()
{
    vector<double> distances; // distances between cities
    cout << "Enter a few distances between cities" << endl;
    for (double dist; cin >> dist;) {
        if (dist <= 0) { cout << "Distance cannot be negative or zero" << endl; continue; }
        distances.push_back(dist);
    }
        
    double sum=0, min_dist, max_dist;
    min_dist = max_dist = distances[0];
    for (double dist : distances) {
        sum += dist;
        if (dist < min_dist) min_dist = dist;
        else if (dist > max_dist) max_dist = dist;
    }
    cout << "Total distance is " << sum << endl;
    cout << "Average distance between two neighboring cities is " << sum / distances.size() << endl;
    // cout << *min_element(distances.begin(), distances.end()) << endl;
    cout << min_dist << endl;
    // cout << *max_element(distances.begin(), distances.end()) << endl;
    cout << max_dist << endl;
    }
