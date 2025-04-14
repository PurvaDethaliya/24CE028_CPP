#include <iostream>
#include <string>
using namespace std;

class Loan
{
private:
    string loan_id;
    string applicant_name;
    double loan_amount;
    double annual_interest_rate;
    int tenure_months;

public:
    Loan(string id, string name, double amount, double interest_rate, int months): loan_id(id), applicant_name(name), loan_amount(amount),annual_interest_rate(interest_rate), tenure_months(months) {}

    double calculate_emi() {
        double R = (annual_interest_rate / 100) / 12;
        double pow_val = 1.0;

        for (int i = 0; i < tenure_months; ++i) {
            pow_val *= (1 + R);
        }

        double emi = (loan_amount * R * pow_val) / (pow_val - 1);
        return emi;
    }

    void loan_summary() {
        double emi = calculate_emi();

        cout << "Loan ID: " << loan_id << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Annual Interest Rate: " << annual_interest_rate << "%" << endl;
        cout << "Loan Tenure (months): " << tenure_months << endl;

        cout << "EMI (Monthly Payment): " << (int)(emi) << "." << (int)((emi - (int)(emi)) * 100) << endl;
    }
};

int main() {
    string loan_id, applicant_name;
    double loan_amount, annual_interest_rate;
    int tenure_months;

    cout << "Enter Loan ID: ";
    cin >> loan_id;
    cout << "Enter Applicant Name: ";
    cin.ignore();
    getline(cin, applicant_name);
    cout << "Enter Loan Amount: ";
    cin >> loan_amount;
    cout << "Enter Annual Interest Rate: ";
    cin >> annual_interest_rate;
    cout << "Enter Loan Tenure (months): ";
    cin >> tenure_months;

    Loan loan(loan_id, applicant_name, loan_amount, annual_interest_rate, tenure_months);

    loan.loan_summary();

    return 0;
}
