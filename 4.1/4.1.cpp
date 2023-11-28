#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> unwanted_words;
    unwanted_words.push_back("Broccoli");
    unwanted_words.push_back("Fuck");
    unwanted_words.push_back("Damn");
    vector<string> words;
    cout << "Enter a few words. Separate input by pressing Enter or Space button.\n";
    for (string temp; cin >> temp;)
        words.push_back(temp);

    for (string wrd : words)
    {
        for (string unwanted_word : unwanted_words)
            if (wrd == unwanted_word) wrd = "BLEEP";
        cout << wrd << endl;
    }

    return 0;
}
