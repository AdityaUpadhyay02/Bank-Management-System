#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        string number, name;
        double initialBalance;

        cout << "Enter account number: ";
        cin >> number;

        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter initial balance: $";
        cin >> initialBalance;

        Account newAccount(number, name, initialBalance);
        accounts.push_back(newAccount);

        cout << "Account created successfully." << endl;
    }

    void displayAccountDetails() {
        string accountNumber;
        cout << "Enter account number: ";
        cin >> accountNumber;

        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Account Number: " << account.getAccountNumber() << endl;
                cout << "Account Holder Name: " << account.getAccountHolderName() << endl;
                cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
                return;
            }
        }

        cout << "Account not found." << endl;
    }

    void performTransaction() {
        string accountNumber;
        double amount;

        cout << "Enter account number: ";
        cin >> accountNumber;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Enter amount: $";
                cin >> amount;

                char choice;
                cout << "Select transaction type (D for deposit, W for withdrawal): ";
                cin >> choice;

                if (choice == 'D' || choice == 'd') {
                    account.deposit(amount);
                } else if (choice == 'W' || choice == 'w') {
                    account.withdraw(amount);
                } else {
                    cout << "Invalid transaction type." << endl;
                }

                return;
            }
        }

        cout << "Account not found." << endl;
    }
};

int main() {
    Bank bank;

    int choice;

    do {
        cout << "Bank Management System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Account Details" << endl;
        cout << "3. Perform Transaction" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.displayAccountDetails();
                break;

            case 3:
                bank.performTransaction();
                break;

            case 4:
                cout << "Exiting program. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
