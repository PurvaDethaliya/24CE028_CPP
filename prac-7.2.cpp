#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file \"" << filename << "\"." << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    size_t totalLines = 0, totalWords = 0, totalChars = 0;

    while (getline(file, line)) {
        lines.push_back(line);
        totalLines++;
        totalChars += line.length() + 1; // +1 for newline character

        istringstream iss(line);
        string word;
        while (iss >> word) {
            totalWords++;
        }
    }

    file.close();

    cout << "Total Lines: " << totalLines << "\n";
    cout << "Total Words: " << totalWords << "\n";
    cout << "Total Characters: " << totalChars << "\n";

    return 0;
}
