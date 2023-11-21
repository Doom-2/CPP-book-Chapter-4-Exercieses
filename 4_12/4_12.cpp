
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
	int max;
	vector<int> primes;
	bool isPrime;
	cout << "Enter max value:" << endl << ">";
	max = cin_positive_int();
	for (size_t i = 2; i <= max; i++)
	{
		isPrime = true;
		for (size_t j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime) primes.push_back(i);
	}
	for (int val : primes) cout << val << endl;
}
