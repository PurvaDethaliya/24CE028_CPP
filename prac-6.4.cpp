#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base class destructor called.\n";
    }

    virtual void show()
    {
        cout << "Base class show method.\n";
    }
};

class Derived : public Base
{
private:
    int* data;

public:
    Derived(int val)
    {
        data = new int(val);
        cout << "Derived class constructor called. Data = " << *data << endl;
    }

    ~Derived()
    {
        delete data;
        cout << "Derived class destructor called. Memory freed.\n";
    }

    void show() override
    {
        cout << "Derived class show method. Data = " << *data << endl;
    }
};

int main()
{
    int value;

    cout << "Enter a value for the Derived class object: ";
    cin >> value;

    Base* ptr = new Derived(value);

    ptr->show();

    delete ptr;

    return 0;
}
