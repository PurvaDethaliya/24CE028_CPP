#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    int choice;
    cout << "Choose collection method:\n";
    cout << "1. Use dynamic collection (vector)\n";
    cout << "2. Use static collection (array)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    vector<unique_ptr<Shape>> shapes;

    if (choice == 1)
    {
        int n;
        cout << "\nEnter number of shapes to manage: ";
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int shapeType;
            cout << "\nEnter 1 for Rectangle or 2 for Circle: ";
            cin >> shapeType;

            if (shapeType == 1)
            {
                double length, width;
                cout << "Enter length and width of rectangle: ";
                cin >> length >> width;
                shapes.push_back(make_unique<Rectangle>(length, width));
            }
            else if (shapeType == 2)
            {
                double radius;
                cout << "Enter radius of circle: ";
                cin >> radius;
                shapes.push_back(make_unique<Circle>(radius));
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }

        cout << "\nAreas of all shapes:\n";
        for (const auto& shape : shapes)
        {
            cout << "Area: " << shape->Area() << endl;
        }
    }
    else if (choice == 2)
    {
        const int MAX_SHAPES = 5;
        Shape* shapeArray[MAX_SHAPES];

        int n;
        cout << "\nEnter number of shapes to manage (up to 5): ";
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int shapeType;
            cout << "\nEnter 1 for Rectangle or 2 for Circle: ";
            cin >> shapeType;

            if (shapeType == 1)
            {
                double length, width;
                cout << "Enter length and width of rectangle: ";
                cin >> length >> width;
                shapeArray[i] = new Rectangle(length, width);
            }
            else if (shapeType == 2)
            {
                double radius;
                cout << "Enter radius of circle: ";
                cin >> radius;
                shapeArray[i] = new Circle(radius);
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }

        cout << "\nAreas of all shapes:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << "Area: " << shapeArray[i]->Area() << endl;
        }

        for (int i = 0; i < n; ++i)
        {
            delete shapeArray[i];
        }
    }
    else
    {
        cout << "Invalid choice!\n";
    }

    return 0;
}

