#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

string toLowercase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordFrequency;

    stringstream ss(sentence);
    string word;

    while (ss >> word)
    {
        word = toLowercase(word);

        while (!word.empty() && !isalpha(word.back()))
        {
            word.pop_back();
        }
        while (!word.empty() && !isalpha(word.front()))
        {
            word.erase(word.begin());
        }

        wordFrequency[word]++;
    }

    cout << "\nWord Frequency Distribution:\n";
    for (const auto& entry : wordFrequency)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}

