
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


// Checks if the string can be converted to a double
bool checkIsDouble(string inputString) {
    char* end;
    double result = strtod(inputString.c_str(), &end);
    if (end == inputString.c_str() || *end != '\0') return false;
    return true;
}


// Converts double to a string and removes trailing zeros as well as the decimal point if any.
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

// Rounds a value using the rounding rule of natural numbers
double round_d(double var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}


int main()
{
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);
    double operand;
    string operation, operand_as_str{};
    vector<double> operands;
    vector<string> numbers;
    numbers.push_back("zero");
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");

    const string GREETINGS = "Enter two operands and operation:'\n'"
                            "Allowed operand values are either any floating point value or the string representation of any digit 1..9\n"
                            "Allowed operations are '+', '-', '*', '/', 'plus', 'minus', 'mul', 'div'.\n"
                            "To abort the program press Esc \n";

    cout << GREETINGS;

    while (true)
    {
        int i = 0;
        operands.clear();
        while (i < 2)
        {
            if (i == 0) cout << "\nEnter the 1st operand\n";
            else cout << "\nEnter the 2nd operand\n";
            getline(cin, operand_as_str);

            if (operand_as_str == "") { cout << "Can't be empty. Please, type anything...\n"; continue; }
            else if (checkIsDouble(operand_as_str)) // if entered value is can be coverted to double
            {
                operand = stod(operand_as_str);
                operands.push_back(operand);
                ++i;
            }
            else
            {
                bool success = false;
                for (int i = 0; i < numbers.size(); ++i) // check if the value is a string representation of any digit 1..9
                {
                    if (operand_as_str == numbers[i])
                    {
                        operands.push_back(i);
                        success = true;
                        break;
                    }
                }
                if (success) { ++i; }
                else { cout << "Unknown value\n"; continue; }
            }
        }
        cout << "Enter an operation\n";
        while (getline(cin, operation))
        {
            // Output results depending on operation type
            if (operation == "+" || operation == "plus")
            {
                cout << "The sum of " << round_d(operands[0]) << " and " << round_d(operands[1]) << " is " << round_d(operands[0] + operands[1]) << endl;
                break;
            }
            else if (operation == "-" || operation == "minus")
            {
                cout << "The difference between " << round_d(operands[0]) << " and " << round_d(operands[1]) << " is " << round_d(operands[0] - operands[1]) << endl;
                break;
            }
            else if (operation == "*" || operation == "mul")
            {
                cout << "The product of " << round_d(operands[0]) << " and " << round_d(operands[1]) << " is " << round_d(operands[0] * operands[1]) << endl;
                break;
            }
            else if (operation == "/" || operation == "div") {
                try {
                    if (operands[1] == 0) {
                        throw logic_error("Divide by zero\n");
                    }
                    else if (operands[0] == 0)
                    {
                        cout << "The quotient of " << 0 << " and " << round_d(operands[1]) << " is 0" << endl;
                        break;
                    }
                    else
                    {
                        cout << "The quotient of " << round_d(operands[0]) << " and " << round_d(operands[1]) << " is " << round_d(operands[0] / operands[1]) << endl;
                        break;
                    }
                }
                catch (logic_error e) {
                    cerr << e.what();
                    break;
                }
            }
            else cout << "'" << operation << "' - unknown operation type.\n";
            cout << "Enter an operation\n";
        }
    }
    return 0;
}
