#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void toLowercase(string &str)
{
    for (char &ch : str)
    {
        ch = tolower(ch);
    }
}

void countWordFrequency(string &text)
{
    string* words = new string[10];
    int* frequencies = new int[10];
    int wordCount = 0;
    int capacity = 10;

    size_t start = 0;
    while (start < text.length())
    {
        size_t end = text.find_first_of(" \n\t", start);
        if (end == string::npos) end = text.length();

        string word = text.substr(start, end - start);

        toLowercase(word);

        bool found = false;
        for (int i = 0; i < wordCount; ++i)
        {
            if (words[i] == word)
            {
                frequencies[i]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (wordCount == capacity)
            {
                capacity *= 2;
                string* newWords = new string[capacity];
                int* newFrequencies = new int[capacity];
                for (int i = 0; i < wordCount; ++i)
                {
                    newWords[i] = words[i];
                    newFrequencies[i] = frequencies[i];
                }
                delete[] words;
                delete[] frequencies;
                words = newWords;
                frequencies = newFrequencies;
            }
            words[wordCount] = word;
            frequencies[wordCount] = 1;
            wordCount++;
        }
        start = end + 1;
    }
    cout << "\nWord Frequency Count:\n";
    for (int i = 0; i < wordCount; ++i)
    {
        cout << words[i] << ": " << frequencies[i] << endl;
    }

    delete[] words;
    delete[] frequencies;
}

int main()
{
    string text;
    cout << "Enter a paragraph (end input with an empty line):\n";

    string line;
    while (true)
    {
        getline(cin, line);
        if (line.empty()) break;
        text += line + " ";
    }

    countWordFrequency(text);

    return 0;
}

