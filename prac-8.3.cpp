#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> transactionIDs;

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; ++i)
    {
        int id;
        cin >> id;
        transactionIDs.insert(id);
    }

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (const auto& id : transactionIDs)
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}

