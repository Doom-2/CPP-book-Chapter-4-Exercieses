
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


// Flushes the cin buffer
void flush_cin()
{
    while (cin.get() != '\n');
    cin.clear();
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
    flush_cin();
    return val;
}


// Checks vector of strings for duplicates, prints them and terminates the program if any
void checkDuplicates(vector<string> &words)
{
    vector<string> duplicates;
    sort(words);

    for (int i = 1; i < words.size(); i++) {
        if (words[i - 1] == words[i]) {

            // push the duplicate words in a new vector string
            if (duplicates.empty())
                duplicates.push_back(words[i]);
            else if (words[i] != duplicates.back())
                duplicates.push_back(words[i]);
        }
    }

    if (duplicates.size())
    {
        cout << "Error! Duplicate names were found:" << endl;
        for (string dup : duplicates)
            cout << dup << endl;
        exit(0);
    }
}


int main()
{
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    vector<string> names, names_by_score;
    vector<int> scores;
    string name{}, user_request;
    int score, req_score;
    bool allDigits;
    const string DATA_FILTERING_PROMPT = "\nEnter name or score to filter data\n"
                                         "To abort the program press Esc\n>";

    const string GREETINGS = "Enter NAME and SCORE separated by a space\n"
                             "Terminate input with 'NoName' as NAME\n"
                             "To abort the program press Esc\n>";

    const string INVALID_NAME_INPUT = "Error! The name must contain at least 1 letter character (a-zA-Z)\n>";

    const string EMPTY_INPUT = "The input cannot be empty. Please, type anything...\n>";


    /* Task 4.19 */
    cout << GREETINGS;
    while (true)
    {
        cin >> name;
        // Check if the string contains at least one letter
        if (!any_of(name.begin(), name.end(), ::isalpha))
        {
            cout << INVALID_NAME_INPUT;
            flush_cin();
            continue;
        }
        // A way to dynamically prevent duplicate words (not used in accordance with the original task)
        /*if (find(names.begin(), names.end(), name) != names.end())
        {
            cout << "The name " << name << " is already exists. Type another one.\n>";
            while (cin.get() != '\n');
            continue;
        }*/

        if (name == "NoName") { flush_cin(); break; }
        score = cin_positive_int();
        names.push_back(name);
        scores.push_back(score);
        cout << "\'" << name << " " << score << "\'" << " has been stored in the database. Enter a new name-and-score pair.\n>";
    }
    if (!names.size()) { cout << "No records were found." << endl; return 0; }

    // Сheck for duplicates and print the results if there are none, or terminate the program otherwise
    checkDuplicates(names);
    cout << endl << setw(15) << left << "NAME" << right << setw(4) << fixed << "SCORE" << endl;
    for (int i = 0; i < names.size(); i++)
        cout << setw(15) << left << names[i] << right << setw(4) << fixed << scores[i] << endl;    


    /* Tasks 4.20 - 4.21 */
    cout << DATA_FILTERING_PROMPT;
    while (getline(cin, user_request))
    {
        bool name_found = false;
        names_by_score.clear();
        if (user_request == "") { cout << EMPTY_INPUT; continue; }
        allDigits = regex_match(user_request, regex("\\d+")); // check that the user means to enter score
        if (allDigits)
        {
            req_score = stoi(user_request); //convert <string> to <int>
            for (int i = 0; i < scores.size(); i++)
                if (scores[i] == req_score)
                    names_by_score.push_back(names[i]);
            if (names_by_score.size() != 0)
            {
                cout << "The following students have " << req_score << " scores:" << endl;
                for (string name : names_by_score)
                    cout << name << endl;
            }
            else
                cout << "Score not found." << endl;
        }
        else // otherwise the user means to enter name
        {
            for (int i = 0; i < names.size(); i++)
                if (names[i] == user_request)
                {
                    cout << names[i] << " has " << scores[i] << " scores" << endl;
                    name_found = true;
                }
                    
            if (!name_found)
                cout << "Name not found." << endl;

        }
        cout << DATA_FILTERING_PROMPT;
    }

    return 0;
}
