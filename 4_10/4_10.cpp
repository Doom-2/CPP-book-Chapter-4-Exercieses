
#include <std_lib_facilities.h>
#include <windows.h>
#include <conio.h>


// Esc key press check
DWORD WINAPI CheckEscape(LPVOID lpParam) {
    while (GetAsyncKeyState(VK_ESCAPE) == 0) {
        //sleep 
        Sleep(500);
    }
    exit(0);
}


// Checks for positive integers, throws an error othewise.
// Returns an integer on success.
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
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    vector<string> items;
    items.push_back("rock");
    items.push_back("paper");
    items.push_back("scissors");
    int user_input{}, computer_input{};
    int min_index = 1, max_index = 3;
    int range = max_index - min_index + 1;
    bool first_game = true;
    while (true)
    {
        if (!first_game) system("CLS");
        cout << "Rock, Paper, Scissors game" << endl;
        cout << "Make a choice or press Esc to exit the program." << endl
             << "1 - Rock\n2 - Paper\n3 - Scissors" << endl
             << ">";

        // check that the user has only entered values 1, 2 or 3
        while (true) 
        {
            user_input = cin_positive_int();
            if (user_input != 1 && user_input != 2 && user_input != 3)
            {
                cout << "Only 1, 2 or 3 is allowed. Try again" << endl
                     << ">";
                continue;
            }
            break;
        }

        computer_input = rand() % range + min_index; // generate a random integer value in the range from 1 to 3
        cout << "Your input is " << items[user_input - 1] << endl;
        cout << "Computer input is " << items[computer_input-1] << endl;

        switch (user_input)
        {
        case 1:
            if (computer_input == 1) cout << "Draw!\n";
            else if (computer_input == 2) cout << "Paper wraps rock\nComputer wins\n";
            else if (computer_input == 3) cout << "Rock dulls scissors\nYou win!\n";
            break;

        case 2:
            if (computer_input == 1) cout << "Paper wraps rock\nYou win!\n";
            else if (computer_input == 2) cout << "Draw!\n";
            else if (computer_input == 3) cout << "Scissors cuts paper\nComputer wins\n";
            break;

        case 3:
            if (computer_input == 1) cout << "Rock dulls scissors\nComputer wins\n";
            else if (computer_input == 2) cout << "Scissors cuts paper\nYou win!\n";
            else if (computer_input == 3) cout << "Draw!\n";
            break;

        default:
            break;
        }
        cout << endl;
        cout << "Press any key to restart the game or press Esc to exit." << endl;
        _getch(); // waits for any keypress
        first_game = false;
    }
}
