#include <iostream>
#include <vector>
using namespace std;

class Shape
{
protected:
    double radius;
public:
    Shape() : radius(0) {}
    Shape(double r) : radius(r) {}

    void setRadius(double r)
    {
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    Circle() : Shape() {}
    Circle(double r) : Shape(r) {}

    double calculateArea() const
    {
        return 3.14159 * radius * radius;
    }

    void displayArea() const
    {
        cout << "Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};

int main()
{
    int choice;
    cout << "Choose method:\n";
    cout << "1. Static Handling (Fixed number of circles)\n";
    cout << "2. Dynamic Handling (Flexible number of circles)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        const int MAX_CIRCLES = 5;
        Circle circles[MAX_CIRCLES];

        cout << "\nYou can enter details for " << MAX_CIRCLES << " circles.\n";
        for (int i = 0; i < MAX_CIRCLES; ++i)
        {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;
            circles[i].setRadius(r);
        }

        cout << "\nAreas of Circles:\n";
        for (int i = 0; i < MAX_CIRCLES; ++i)
        {
            cout << "Circle " << i + 1 << ": ";
            circles[i].displayArea();
        }
    }
    else if (choice == 2)
    {
        int n;
        cout << "\nEnter number of circles: ";
        cin >> n;

        vector<Circle> circles;

        for (int i = 0; i < n; ++i)
        {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;
            circles.push_back(Circle(r));
        }

        cout << "\nAreas of Circles:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << "Circle " << i + 1 << ": ";
            circles[i].displayArea();
        }
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}

