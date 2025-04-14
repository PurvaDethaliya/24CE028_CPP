#include <iostream>
#include <vector>
#include <string>

class BankAccount
{
private:
    std::string accountHolder;
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string holder, std::string number, double initialBalance = 0.0): accountHolder(holder), accountNumber(number), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        }
        else
        {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        }
        else if (amount > balance)
        {
            std::cout << "Insufficient funds." << std::endl;
        }
        else
        {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }

    void displayAccountSummary()
    {
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

int main()
{
    std::string accountHolder, accountNumber;
    double initialBalance, depositAmount, withdrawAmount;

    std::cout << "Enter account holder name for Account 1: ";
    std::getline(std::cin, accountHolder);
    std::cout << "Enter account number for Account 1: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Enter initial balance for Account 1: ";
    std::cin >> initialBalance;
    std::cin.ignore(); // To ignore the newline character left by std::cin

    BankAccount account1(accountHolder, accountNumber, initialBalance);

    std::cout << "Enter deposit amount for Account 1: ";
    std::cin >> depositAmount;
    account1.deposit(depositAmount);

    std::cout << "Enter withdrawal amount for Account 1: ";
    std::cin >> withdrawAmount;
    account1.withdraw(withdrawAmount);

    account1.displayAccountSummary();

    std::cout << "\nEnter account holder name for Account 2: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolder);
    std::cout << "Enter account number for Account 2: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Enter initial balance for Account 2: ";
    std::cin >> initialBalance;
    std::cin.ignore();
    BankAccount account2(accountHolder, accountNumber, initialBalance);

    std::cout << "Enter deposit amount for Account 2: ";
    std::cin >> depositAmount;
    account2.deposit(depositAmount);

    std::cout << "Enter withdrawal amount for Account 2: ";
    std::cin >> withdrawAmount;
    account2.withdraw(withdrawAmount);

    account2.displayAccountSummary();

    return 0;
}
