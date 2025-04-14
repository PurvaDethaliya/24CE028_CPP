#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string name;
    double basic_salary;
    double bonus;

public:
    Employee(string employee_name, double salary, double employee_bonus = 5000)
        : name(employee_name), basic_salary(salary), bonus(employee_bonus) {}

    inline double calculate_total_salary() const {
        return basic_salary + bonus;
    }


    void display_employee_details() const {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculate_total_salary() << endl;
    }
};

int main() {
    vector<Employee> employees;
    char more_employees = 'y';
    while (more_employees == 'y' || more_employees == 'Y') {
        string name;
        double salary, bonus;

        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> salary;

        cout << "Enter Bonus (or 0 for default): ";
        cin >> bonus;

        if (bonus == 0) {
            bonus = 5000;
        }

        employees.push_back(Employee(name, salary, bonus));

        cout << "Do you want to enter more employees (y/n)? ";
        cin >> more_employees;
    }

    cout << "\nEmployee Details:\n";
    for (const auto& employee : employees) {
        employee.display_employee_details();
        cout << "------------------------\n";
    }

    return 0;
}
