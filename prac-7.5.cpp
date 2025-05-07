#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

ostream& currency(ostream& os) {
    os << "rupees ";
    return os;
}

struct Student {
    string name;
    float marks;
    float tuitionFee;
};

void displayStudents(Student students[], int count) {
    cout << "\n======= Student Academic Report =======\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(20) << students[i].name
             << setw(10) << fixed << setprecision(2) << students[i].marks
             << currency << setw(14) << fixed << setprecision(2) << students[i].tuitionFee << endl;
    }
}

int main()
{
    Student students[] = {
        {"Purva", 90.5f, 49000.00f},
        {"Reeva", 91.0f, 47500.50f},
        {"Sakshi", 90.25f, 44000.75f},

    };

    int studentCount = sizeof(students) / sizeof(students[0]);

    displayStudents(students, studentCount);
    return 0;
}
