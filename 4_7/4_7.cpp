
#include <std_lib_facilities.h>
#include <conio.h>
#include <Windows.h>

DWORD WINAPI CheckEscape(LPVOID lpParam) {
    while (GetAsyncKeyState(VK_ESCAPE) == 0) {
        //sleep 
        Sleep(10);
    }
    exit(0);

}

double cin_double_with_check()
{
    double val;
    string s;
    while (1) {
        getline(cin,s);
        if (s == "") continue;
        char* p;
        val = strtod(s.c_str(), &p);
        if (*p == 0) return val;
        else cout << "Invalid input! Only decimal value is allowed.\n" << "Try again\n";
    }
}

string rm_end_zeros(double val)
{
    string valAsString = to_string(val);
    if (valAsString.find('.') != string::npos)
    {
        // Remove trailing zeroes
        valAsString = valAsString.substr(0, valAsString.find_last_not_of('0') + 1);
        // If the decimal point is now the last character, remove that as well
        if (valAsString.find('.') == valAsString.size() - 1)
        {
            valAsString = valAsString.substr(0, valAsString.size() - 1);
        }
    }
    return valAsString;
}

int main()
{
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);
    double operand;
    string operation;
    vector<double> operands;

    cout.setf(ios::fixed);
    cout << "Enter two operands and operation:'\n'";
    cout << "Allowed operations are '+', '-', '*', '/', 'plus', 'minus', 'mul', 'div'.\n";
    cout << "To abort the program press Esc \n";

    while (true)
    { 
        int i = 0;
        operands.clear();
        while (i < 2)
        {
            if (i == 0) cout << "\nEnter the 1st operand\n";
            else cout << "Enter the 2nd operand\n";
            operand = cin_double_with_check();
            operands.push_back(operand);
            ++i;
        }

        cout << "Enter an operation\n";
        while (getline(cin, operation))
        {
            cout << setprecision(2);
            if (operation == "+" || operation == "plus")
            {
                cout << "The sum of " << rm_end_zeros(operands[0]) << " and " << rm_end_zeros(operands[1]) << " is " <<  rm_end_zeros(operands[0] + operands[1]) << endl;
                break;
            }
            else if (operation == "-" || operation == "minus")
            {
                cout << "The difference between " << rm_end_zeros(operands[0]) << " and " << rm_end_zeros(operands[1]) << " is " << rm_end_zeros(operands[0] - operands[1]) << endl;
                break;
            }
            else if (operation == "*" || operation == "mul")
            {
                cout << "The product of " << rm_end_zeros(operands[0]) << " and " << rm_end_zeros(operands[1]) << " is " << rm_end_zeros(operands[0] * operands[1]) << endl;
                break;
            }
            else if (operation == "/" || operation == "div") {
                try {
                    if (operands[1] == 0) {
                        throw logic_error("Divide by zero\n");
                    }
                    else if (operands[0] == 0)
                    {
                        cout << "The quotient of " << 0 << " and " << rm_end_zeros(operands[1]) << " is 0" << endl;
                        break;
                    }
                    else
                    {
                        cout << "The quotient of " << rm_end_zeros(operands[0]) << " and " << rm_end_zeros(operands[1]) << " is " << operands[0] / operands[1] << endl;
                        break;
                    }
                }
                catch (logic_error e) {
                    cerr << e.what();
                    break;
                }
            }
            else if (operation == "q") { cout << "Exiting the program.." << endl; return 0; }
            else cout << "'" << operation << "' - unknown operation type.\n";
            cout << "Enter an operation\n";
        }
        
    }
    return 0;
}
