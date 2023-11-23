
#include <std_lib_facilities.h>


int cin_positive_int()
{
    int val;
    do {
        try {
            if (!(cin >> val)) throw 1;
            if (cin.good() && val < 2 && cin.peek() == '\n') throw 2;
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
                cerr << "Invalid input! An integer must be great or equal then 2.\n" << ">";
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
	vector<int> primes;
    int max;
    cout << "Enter the end of the range" << endl;
    max = cin_positive_int();

	// Step 1. Fill the vector with all integers in the range from 2 to 100.
	for (int i = 2; i <= max; i++) primes.push_back(i);

	for (int j = 0;; j++) // Step 4. Move to the next integer that has not been processed
	{
		if (pow(primes[j], 2) > max) break; // Step 5. Break the loop if the current integer squared is greater than the end of the range 
		for (int i = 0; i < primes.size(); i++) // Step 2. Iterate over each value of the vector by its index
		{
			// Step 3. Remove from the vector all integers that are multiples of the current integer, starting with current one squared
			// After removing, erase the last unused position from the vector as well
			if (primes[i] < pow(primes[j], 2)) continue;
			if (primes[i] % primes[j] == 0) { primes.erase(remove(primes.begin(), primes.end(), primes[i]), primes.end()); }
		}
	}
	// Output all primes in current range
	for (int prime : primes) cout << prime << endl;
}
