#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool isValidNumber(const string& input)
{
    for (char c : input)
    {
        if (!isdigit(c) && c != '.')
        {
            return false;
        }
    }
    return true;
}

void calculateLoanToIncomeRatio()
{
    float loanAmount, annualIncome;
    string loanInput, incomeInput;

    while (true)
    {
        cout << "Enter the loan amount: ";
        cin >> loanInput;
        if (isValidNumber(loanInput))
        {
            loanAmount = stof(loanInput);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid number for the loan amount.\n";
        }
    }

    while (true)
    {
        cout << "Enter the annual income: ";
        cin >> incomeInput;
        if (isValidNumber(incomeInput))
        {
            annualIncome = stof(incomeInput);
            if (annualIncome == 0)
            {
                cout << "Income cannot be zero. Please enter a valid annual income.\n";
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a valid number for the annual income.\n";
        }
    }

    float ratio = loanAmount / annualIncome;

    cout << "\nLoan-to-Income Ratio: " << ratio << endl;
}

int main()
{
    int choice;

    do {
        cout << "\n==== Financial Calculator ====\n";
        cout << "1. Calculate Loan-to-Income Ratio\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculateLoanToIncomeRatio();
                break;
            case 2:
                cout << "Thank you for using the financial calculator.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 2);

    return 0;
}

