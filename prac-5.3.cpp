#include <iostream>
#include <stack>
using namespace std;

class Point
{
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    Point operator-() const
    {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const
    {
        return (x == other.x && y == other.y);
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class CustomStack
{
private:
    Point arr[100];
    int topIndex;
public:
    CustomStack() : topIndex(-1) {}

    void push(Point p)
    {
        if (topIndex < 99)
            arr[++topIndex] = p;
        else
            cout << "Stack Overflow!\n";
    }

    Point pop()
    {
        if (topIndex >= 0)
            return arr[topIndex--];
        else
        {
            cout << "Stack Underflow!\n";
            return Point();
        }
    }

    bool empty()
    {
        return (topIndex == -1);
    }
};

int main()
{
    int choice;
    cout << "Choose stack method:\n";
    cout << "1. Use STL stack\n";
    cout << "2. Use custom stack\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    stack<Point> historyStack;
    CustomStack customHistoryStack;

    Point currentPoint;
    cout << "\nInitialize current point:\n";
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    currentPoint = Point(x, y);

    bool running = true;
    while (running) {
        cout << "\nCurrent Point: ";
        currentPoint.display();
        cout << "\n";

        cout << "\nChoose an operation:\n";
        cout << "1. Negate the point (-Point)\n";
        cout << "2. Add another point (Point + Point)\n";
        cout << "3. Compare with another point (Point == Point)\n";
        cout << "4. Undo last operation\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        int op;
        cin >> op;

        switch (op)
        {
            case 1:
            {
                if (choice == 1) historyStack.push(currentPoint);
                else customHistoryStack.push(currentPoint);

                currentPoint = -currentPoint;
                cout << "Negated successfully!\n";
                break;
            }
            case 2:
            {
                int addX, addY;
                cout << "Enter x of point to add: ";
                cin >> addX;
                cout << "Enter y of point to add: ";
                cin >> addY;
                Point toAdd(addX, addY);

                if (choice == 1) historyStack.push(currentPoint);
                else customHistoryStack.push(currentPoint);

                currentPoint = currentPoint + toAdd;
                cout << "Added successfully!\n";
                break;
            }
            case 3:
            {
                int cmpX, cmpY;
                cout << "Enter x of point to compare: ";
                cin >> cmpX;
                cout << "Enter y of point to compare: ";
                cin >> cmpY;
                Point toCompare(cmpX, cmpY);

                if (currentPoint == toCompare)
                    cout << "Points are equal.\n";
                else
                    cout << "Points are NOT equal.\n";
                break;
            }
            case 4:
            {
                if (choice == 1)
                {
                    if (!historyStack.empty())
                    {
                        currentPoint = historyStack.top();
                        historyStack.pop();
                        cout << "Undo successful!\n";
                    }
                    else
                    {
                        cout << "Nothing to undo.\n";
                    }
                }
                else
                {
                    if (!customHistoryStack.empty())
                    {
                        currentPoint = customHistoryStack.pop();
                        cout << "Undo successful!\n";
                    }
                    else
                    {
                        cout << "Nothing to undo.\n";
                    }
                }
                break;
            }
            case 5:
            {
                running = false;
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
