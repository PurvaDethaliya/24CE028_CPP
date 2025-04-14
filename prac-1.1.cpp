#include<iostream>
using namespace std;

class Account
{
private:
   char account_holder_name[100];
   int account_number;
   int balance;

public:

   void account_detail();
   void display_detail();
   void deposit(double amount);
   void withdraw(double amount);
   void check_balance() const;

};

void Account::account_detail()
{
    cout<<"Account holder : ";
    cin>>account_holder_name;
    cout<<"Account number : ";
    cin>>account_number;
    cout<<"Account balance : ";
    cin>>balance;
}

void Account::display_detail()
{
    cout<<"\nAccount detail : ";
    cout<<"\nAccount holder : "<<account_holder_name<<endl;
    cout<<"Account number : "<<account_number<<endl;
    cout<<"Account balance : "<<balance<<endl;
}

void Account::deposit(double amount)
{
    if (amount > 0)
    {
       balance += amount;
       cout << "Deposited " << amount << ", New balance: " << balance << endl;
    }
    else
    {
       cout << "Invalid deposit amount!" << endl;
    }
}


void Account::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
      balance -= amount;
      cout << "Withdrew " << amount << ", New balance: " << balance << endl;
    }
    else if (amount > balance)
    {
      cout << "Error: Insufficient funds!" << endl;
    }
    else
    {
      cout << "Invalid withdrawal amount!" << endl;
    }
}

void Account::check_balance() const
{
    cout << "Current balance: " << balance << endl;
}

int main()
{
    Account a1;

    a1.account_detail();
    a1.display_detail();

    double depositAmount;
    cout << "\nEnter amount to deposit: ";
    cin >> depositAmount;
    a1.deposit(depositAmount);

    double withdrawalAmount;
    cout << "\nEnter amount to withdraw: ";
    cin >> withdrawalAmount;
    a1.withdraw(withdrawalAmount);

    a1.check_balance();

    return 0;
}
