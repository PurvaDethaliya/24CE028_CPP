#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person
{
protected:
    int employeeID;
public:
    Employee() : Person(), employeeID(0) {}
    Employee(string n, int a, int id) : Person(n, a), employeeID(id) {}

    void displayEmployee() const
    {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee
{
private:
    string department;
public:
    Manager() : Employee(), department("") {}
    Manager(string n, int a, int id, string dept) : Employee(n, a, id), department(dept) {}

    void displayManager() const
    {
        displayEmployee();
        cout << "Department: " << department << endl;
    }

    int getEmployeeID() const
    {
        return employeeID;
    }
};

int main()
{
    int choice;
    cout << "Choose method:\n";
    cout << "1. Static Handling (Fixed number of managers)\n";
    cout << "2. Efficient Retrieval (Using employee ID)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        const int MAX_MANAGERS = 3;
        Manager managers[MAX_MANAGERS];

        cout << "\nYou can enter details for " << MAX_MANAGERS << " managers.\n";
        for (int i = 0; i < MAX_MANAGERS; ++i)
        {
            string name, department;
            int age, employeeID;

            cout << "Enter details for Manager " << i + 1 << ":\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cout << "Employee ID: ";
            cin >> employeeID;
            cout << "Department: ";
            cin.ignore();
            getline(cin, department);

            managers[i] = Manager(name, age, employeeID, department);
        }

        cout << "\nManager Details:\n";
        for (int i = 0; i < MAX_MANAGERS; ++i)
        {
            cout << "\nManager " << i + 1 << ":\n";
            managers[i].displayManager();
        }
    }
    else if (choice == 2)
    {
        int n;
        cout << "\nEnter number of managers: ";
        cin >> n;

        map<int, Manager> managerMap;

        for (int i = 0; i < n; ++i)
        {
            string name, department;
            int age, employeeID;

            cout << "Enter details for Manager " << i + 1 << ":\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cout << "Employee ID: ";
            cin >> employeeID;
            cout << "Department: ";
            cin.ignore();
            getline(cin, department);

            managerMap[employeeID] = Manager(name, age, employeeID, department);
        }

        cout << "\nManager Details:\n";
        for (auto& pair : managerMap)
        {
            cout << "\nEmployee ID: " << pair.first << endl;
            pair.second.displayManager();
        }

        int searchID;
        cout << "\nEnter an Employee ID to search for a manager: ";
        cin >> searchID;

        if (managerMap.find(searchID) != managerMap.end())
        {
            cout << "Manager found:\n";
            managerMap[searchID].displayManager();
        }
        else
        {
            cout << "Manager with ID " << searchID << " not found.\n";
        }
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}

