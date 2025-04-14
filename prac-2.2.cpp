#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
private:
    int roll_number;
    string name;
    int marks[3];
    double average;

public:
    Student()
    {
        roll_number = 0;
        name = "Unknown";
        marks[0] = marks[1] = marks[2] = 0;
        average = 0.0;
    }

    Student(int roll, string student_name, int mark1, int mark2, int mark3)
    {
        roll_number = roll;
        name = student_name;
        marks[0] = mark1;
        marks[1] = mark2;
        marks[2] = mark3;
        calculateAverage();
    }

    void calculateAverage()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void displayStudentDetails() const
    {
        cout << "Roll Number: " << roll_number << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << average << endl;
    }

    double getAverage() const
    {
        return average;
    }
};

void displayAllStudents(const vector<Student>& students)
{
    for (const auto& student : students)
    {
        student.displayStudentDetails();

    }
}

int main()
{
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i)
    {
        int roll;
        string name;
        int mark1, mark2, mark3;

        cout << "Enter details for student " << i + 1 << ":" << endl;

        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter marks for 3 subjects: ";
        cin >> mark1 >> mark2 >> mark3;

        students.push_back(Student(roll, name, mark1, mark2, mark3));
    }

    cout << "\nDisplaying all students: " << endl;
    displayAllStudents(students);

    return 0;
}
