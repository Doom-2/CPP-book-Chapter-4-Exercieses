
#include <std_lib_facilities.h>

int main()
{
    int digit;
    string  digit_as_str{},
            greeting = "Enter a digit or its corresponding spelled-out value, or 'q' to quit\n",
            unknown = "Unknown value\n";
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
    cout << greeting;
    while (getline(cin, digit_as_str))
    {
        if (digit_as_str == "") { cout << "Please, type anything...\n"; continue; }
        bool allDigits = regex_match(digit_as_str, regex("\\d+"));
        if (allDigits)
        {
            digit = stoi(digit_as_str);
            if (digit >= 0 && digit <= 9)
                cout << "You've entered " << numbers[digit] << endl << greeting;
            else
                cout << unknown << greeting;
        }
        else
        {
            if (digit_as_str == "q") break;
            bool success = false;
            for (int i = 0; i < numbers.size(); ++i)
                if (digit_as_str == numbers[i])
                {
                    cout << digit_as_str << " is " << i << endl;
                    success = true;
                    break;
                }
            if (success) cout << greeting;
            else cout << unknown << greeting;
        }
    }
    cout << "Exiting the program...\n";
    return 0;
}

