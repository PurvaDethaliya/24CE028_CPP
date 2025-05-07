#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class DirectoryManager
{
private:
    map<string, vector<string>> directory;

public:
    void createFolder(const string& folderName)
    {
        if (directory.find(folderName) == directory.end())
        {
            directory[folderName] = vector<string>();
            cout << "Folder '" << folderName << "' created successfully.\n";
        }
        else
        {
            cout << "Folder '" << folderName << "' already exists.\n";
        }
    }

    void addFileToFolder(const string& folderName, const string& fileName)
    {
        auto folder = directory.find(folderName);
        if (folder != directory.end())
        {
            folder->second.push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        }
        else
        {
            cout << "Folder '" << folderName << "' does not exist.\n";
        }
    }

    void displayDirectory()
    {
        cout << "\nDirectory Structure:\n";
        for (auto& folder : directory)
        {
            cout << folder.first << ":\n";
            sort(folder.second.begin(), folder.second.end());
            for (const auto& file : folder.second)
            {
                cout << "  " << file << endl;
            }
        }
    }
};

int main()
{
    DirectoryManager dirManager;
    int choice;

    while (true)
    {
        cout << "\nDirectory Management System\n";
        cout << "1. Create Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string folderName;
            cout << "Enter folder name: ";
            cin.ignore();
            getline(cin, folderName);
            dirManager.createFolder(folderName);
        }
        else if (choice == 2)
        {
            string folderName, fileName;
            cout << "Enter folder name: ";
            cin.ignore();
            getline(cin, folderName);
            cout << "Enter file name: ";
            getline(cin, fileName);
            dirManager.addFileToFolder(folderName, fileName);
        }
        else if (choice == 3)
        {
            dirManager.displayDirectory();
        }
        else if (choice == 4)
        {
            cout << "Exiting the system.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

