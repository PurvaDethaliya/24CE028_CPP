#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compareScores(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<pair<string, int>> students;

    cout << "Enter the student names and their scores:\n";
    for (int i = 0; i < n; ++i)
    {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter score for " << name << ": ";
        cin >> score;
        students.push_back(make_pair(name, score));
    }

    sort(students.begin(), students.end(), compareScores);

    cout << "\nRanked List of Students:\n";
    cout << "Rank | Name                | Score\n";
    cout << "-------------------------------------\n";
    int rank = 1;
    for (const auto& student : students)
    {
        cout << rank << "    | " << student.first << " | " << student.second << endl;
        rank++;
    }

    return 0;
}

