#include <iostream>
#include <vector>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    friend istream& operator>>(istream& in, Complex& c)
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        if (c.imag >= 0)
            out << c.real << " + " << c.imag << "i";
        else
            out << c.real << " - " << -c.imag << "i";
        return out;
    }
};

int main()
{
    int n;
    cout << "Enter number of complex numbers to handle: ";
    cin >> n;

    vector<Complex> complexNumbers(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter Complex Number " << i + 1 << ":\n";
        cin >> complexNumbers[i];
    }

    cout << "\nComplex Numbers Entered:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Complex " << i + 1 << ": " << complexNumbers[i] << endl;
    }

    Complex sum;
    for (int i = 0; i < n; ++i)
    {
        sum = sum + complexNumbers[i];
    }
    cout << "\nSum of all complex numbers: " << sum << endl;

    Complex diff = complexNumbers[0];
    for (int i = 1; i < n; ++i)
    {
        diff = diff - complexNumbers[i];
    }
    cout << "Subtraction result (first - rest): " << diff << endl;

    return 0;
}

