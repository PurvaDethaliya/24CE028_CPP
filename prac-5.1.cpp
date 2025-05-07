#include <iostream>
#include <vector>
using namespace std;

class Calculator
{
private:
    vector<double> results;
public:
    int add(int a, int b)
    {
        int result = a + b;
        results.push_back(result);
        return result;
    }

    float add(float a, float b)
    {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    float add(int a, float b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    float add(float a, int b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    void displayResults() const
    {
        cout << "\nStored Results:\n";
        for (size_t i = 0; i < results.size(); ++i)
        {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

int main()
{
    Calculator calc;
    int operations;

    cout << "Enter number of addition operations you want to perform: ";
    cin >> operations;

    for (int i = 0; i < operations; ++i)
    {
        int choice;
        cout << "\nChoose addition type for operation " << i + 1 << ":\n";
        cout << "1. int + int\n";
        cout << "2. float + float\n";
        cout << "3. int + float\n";
        cout << "4. float + int\n";
        cout << "Enter choice (1-4): ";
        cin >> choice;

        if (choice == 1)
        {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            int result = calc.add(a, b);
            cout << "Sum: " << result << endl;
        }
        else if (choice == 2)
        {
            float a, b;
            cout << "Enter two floats: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Sum: " << result << endl;
        }
        else if (choice == 3)
        {
            int a;
            float b;
            cout << "Enter an integer and a float: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Sum: " << result << endl;
        }
        else if (choice == 4)
        {
            float a;
            int b;
            cout << "Enter a float and an integer: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Sum: " << result << endl;
        }
        else
        {
            cout << "Invalid choice. Skipping this operation.\n";
        }
    }
    calc.displayResults();

    return 0;
}
