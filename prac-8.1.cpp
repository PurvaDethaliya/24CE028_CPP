#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void reverseWithStd(vector<int>& seq)
{
    std::reverse(seq.begin(), seq.end());
}

void reverseWithIterators(vector<int>& seq)
{
    auto left = seq.begin();
    auto right = seq.end() - 1;

    while (left < right)
    {
        swap(*left, *right);
        ++left;
        --right;
    }
}

void displaySequence(const vector<int>& seq)
{
    for (const int& num : seq)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> seq(n);

    cout << "Enter the elements of the sequence:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> seq[i];
    }

    int choice;
    cout << "\nChoose the reversal method:\n";
    cout << "1. Using std::reverse()\n";
    cout << "2. Using iterators\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        reverseWithStd(seq);
        cout << "\nReversed sequence using std::reverse(): ";
        displaySequence(seq);
    }
    else if (choice == 2)
    {
        reverseWithIterators(seq);
        cout << "\nReversed sequence using iterators: ";
        displaySequence(seq);
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}

