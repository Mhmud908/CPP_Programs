#include <iostream>
#include <string>
#include <map>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrawn: " << amount << "\n";
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!\n";
        }
    }

void checkBalance() const {
        cout << "Account Balance: " << balance << "\n";
    }
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    map<string, BankAccount> accounts; 
    
    while (true) {
        cout << "\n=== Banking System Menu ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 6) {
            cout << "Thank you for using the banking system!\n";
            break;
        }

        string accNumber;
        switch (choice) {
        case 1: {
            string name;
            double initialBalance;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNumber;
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            if (accounts.find(accNumber) == accounts.end()) {
                accounts[accNumber] = BankAccount(name, accNumber, initialBalance);
                cout << "Account created successfully!\n";
            } else {
                cout << "Account number already exists!\n";
            }
            break;
        }
        case 2:
            cout << "Enter Account Number: ";
            cin >> accNumber;
            if (accounts.find(accNumber) != accounts.end()) {
                double depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                accounts[accNumber].deposit(depositAmount);
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNumber;
            if (accounts.find(accNumber) != accounts.end()) {
                double withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                accounts[accNumber].withdraw(withdrawAmount);
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNumber;
            if (accounts.find(accNumber) != accounts.end()) {
                accounts[accNumber].checkBalance();
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accNumber;
            if (accounts.find(accNumber) != accounts.end()) {
                accounts[accNumber].displayAccountDetails();
            } else {
                cout << "Account not found!\n";
            }
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
