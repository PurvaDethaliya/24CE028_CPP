#include <iostream>
#include <stack>
using namespace std;

class BankAccount
{
protected:
    string accNum;
    double balance;
public:
    BankAccount(string acc, double bal) : accNum(acc), balance(bal) {}

    void deposit(double amt)
    {
        balance += amt;
        cout << "Deposited: " << amt << ", Balance: " << balance << endl;
    }

    virtual int withdraw(double amt)
    {
        if (balance >= amt)
        {
            balance -= amt;
            cout << "Withdrawn: " << amt << ", Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient balance!\n";
            return 0;
        }
    }
    double getBalance() const
    {
        return balance;
    }
};

class SavingAccount : public BankAccount {
public:
    SavingAccount(string acc, double bal) : BankAccount(acc, bal) {}
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(string acc, double bal, double limit) : BankAccount(acc, bal), overdraftLimit(limit) {}
    int withdraw(double amt) override {
        if (balance + overdraftLimit >= amt) {
            balance -= amt;
            cout << "Withdrawn: " << amt << ", Balance: " << balance << endl;
            return 1;
        } else {
            cout << "Overdraft limit exceeded!\n";
            return 0;
        }
    }
    double getOverdraftLimit() const
    {
        return overdraftLimit;
    }
};

struct Transaction
{
    string type;
    double amt;
};

void showMenu()
{
    cout << "\n1. Deposit\n2. Withdraw\n3. Undo\n4. Show Balance\n0. Exit\nEnter your choice: ";
}

int main()
{
    string type, accNum;
    double bal;
    cout << "Account type (savings/current): ";
    cin >> type;
    cout << "Account number: ";
    cin >> accNum;
    cout << "Initial balance: ";
    cin >> bal;

    stack<Transaction> history;
    int ch;
    double amt;

    if (type == "savings")
    {
        SavingAccount acc(accNum, bal);
        do {
            showMenu();
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                {
                    history.push({"withdraw", amt});
                }
                break;
            case 3:
                if (!history.empty())
                {
                    Transaction last = history.top();
                    history.pop();
                    cout << "Undoing " << last.type << " of " << last.amt << endl;
                    if (last.type == "deposit")
                    {
                        acc.withdraw(last.amt);
                    }
                    else
                    {
                        acc.deposit(last.amt);
                    }
                }
                else
                {
                    cout << "No transaction to undo.\n";
                }
                break;
            case 4:
                cout << "Balance: " << acc.getBalance() << endl;
                break;
            }
        } while (ch != 0);
    }
    else if (type == "current")
    {
        double limit;
        cout << "Overdraft limit: ";
        cin >> limit;
        CurrentAccount acc(accNum, bal, limit);
        do {
            showMenu();
            cin >> ch;
            switch (ch) {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                {
                    history.push({"withdraw", amt});
                }
                break;
            case 3:
                if (!history.empty())
                {
                    Transaction last = history.top();
                    history.pop();
                    cout << "Undoing " << last.type << " of " << last.amt << endl;
                    if (last.type == "deposit")
                    {
                        if (acc.getBalance() - last.amt >= -acc.getOverdraftLimit())
                        {
                            acc.withdraw(last.amt);
                        }
                        else
                        {
                            cout << "Cannot undo deposit - Overdraft limit will be exceeded.\n";
                        }
                    }
                    else
                    {
                        acc.deposit(last.amt);
                    }
                }
                else
                {
                    cout << "No transaction to undo.\n";
                }
                break;
            case 4:
                cout << "Balance: " << acc.getBalance() << endl;
                break;
            }
        } while (ch != 0);
    }

    return 0;
}
