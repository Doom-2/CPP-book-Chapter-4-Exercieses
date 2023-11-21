
#include <std_lib_facilities.h>

int main()
{
    vector<int> primes;
	bool isPrime;
	for (size_t i = 2; i <= 100; i++)
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
