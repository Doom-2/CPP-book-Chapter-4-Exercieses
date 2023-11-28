
#include <iostream>
using namespace std;

int main()
{
    double a, b, res = 0.0;
    int oper;
    cout << "Enter 2 numbers\n";
    cin >> a >> b;
    cout << "Select an operation\n" << "1. addition\n" << "2. subtraction\n" << "3. multiplication\n" << "4. division\n";
    cin >> oper;

    switch (oper)
    {

    case 1:
        cout << a << " + " << b << " = " << a + b;
        break;

    case 2:

        cout << a << " - " << b << " = " << a - b;
        break;
    case 3:

        cout << a << " * " << b << " = " << a * b;
        break;
    case 4:
        if (b == 0)
        {
            cout << "Division by 0 is impossible";
            break;
        }
        cout << a << " / " << b << " = " << a / b;
        break;

    default:
        cout << "The operation is not in the list. Enter an integer from 1 to 4";
        break;
    }

    return 0;
}
