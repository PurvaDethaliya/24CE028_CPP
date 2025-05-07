#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    Point* shift(double xOffset, double yOffset)
    {
        x += xOffset;
        y += yOffset;
        return this;
    }

    void display() const
    {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

int main()
{
    double initialX, initialY;
    cout << "Enter initial x-coordinate of the point: ";
    cin >> initialX;
    cout << "Enter initial y-coordinate of the point: ";
    cin >> initialY;

    Point p(initialX, initialY);
    p.display();

    int numShifts;
    cout << "\nHow many shifts would you like to apply? ";
    cin >> numShifts;

    for (int i = 0; i < numShifts; ++i)
    {
        double xOffset, yOffset;
        cout << "Enter x offset for shift " << i + 1 << ": ";
        cin >> xOffset;
        cout << "Enter y offset for shift " << i + 1 << ": ";
        cin >> yOffset;

        p.shift(xOffset, yOffset);
    }

    cout << "\nFinal position of the point: ";
    p.display();

    return 0;
}
