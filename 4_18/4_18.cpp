
#include <std_lib_facilities.h>
#include <conio.h>
#include <Windows.h>

DWORD WINAPI CheckEscape(LPVOID lpParam) {
	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		//sleep 
		Sleep(300);
	}
	exit(0);

}


double cin_double_with_check(const char ch)
{
	double val;
	string s;
	while (1) {

		cin >> s;
		char* p;
		val = strtod(s.c_str(), &p);
		if (*p == 0) {
			return val;
		}
		else
		{
			cout << "Invalid input! Only decimal value is allowed.\n" << "Try again\n"<< ch <<"=";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}


// Rounds a value to n decimal places according to the precision, using the rounding rule of natural numbers
double round_d(double var, int precision)
{
	// if precision = 3 then
	// 37.66666 * 10^3 =37666.66
	// 37666.66 + .5 =37667.1    for rounding off value
	// then type cast to <int> so value is 37667
	// then divided by 10^3 so the value converted into 37.667
	if (precision < 0) precision = 0;
	double value = (var >= 0) ? (int)(var * pow(10, precision) + .5) : (int)(var * pow(10, precision) - .5);
	return value / pow(10, precision);
}


int main()
{
	CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    double a, b, c, x1, x2, discr, discr_mod;
	int precicion = 3; // rounding accuracy for doubles
    cout << "Solution of the quadratic equation\n"
			"ax2 + bx + c = 0\n"
			"To abort the program press Esc" << endl << endl;
    cout << "Enter arguments:\na=";
	a = cin_double_with_check('a');
	cout << "b=";
	b = cin_double_with_check('b');
	cout << "c=";
	c = cin_double_with_check('c');
	discr = pow(b, 2) - 4 * a * c;
	if (a == 0 && b == 0) cout << "The quadratic equation has no solution. 'a' and 'b' cannot together equal 0" << endl;
	else if (a == 0 and b != 0)
	{
		cout << "x=" << round_d(-c / b, precicion);
	}
	else
	{
		if (discr > 0)
		{
			x1 = (-b + sqrt(discr)) / (2 * a);
			x2 = (-b - sqrt(discr)) / (2 * a);
			cout << "x1=" << round_d(x1, precicion) << endl << "x2=" << round_d(x2, precicion) << endl;
		}
		else if (discr == 0)
		{
			x1 = -b / (2 * a);
			cout << "x=" << round_d(x1, precicion) << endl;
		}
		else
		{
			discr_mod = abs(discr);
			cout << "The quadratic equation has no real roots." << endl;
			cout << "x1=" << round_d(-b / (2 * a), precicion) << "-" << round_d(sqrt(discr_mod) / abs((2 * a)), precicion) << "i" << endl;
			cout << "x2=" << round_d(-b / (2 * a), precicion) << "+" << round_d(sqrt(discr_mod) / abs((2 * a)), precicion) << "i" << endl;
		}
	}
}
