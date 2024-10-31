#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    // Constructor to initialize each account
    BankAccount(int accNum, double bal, string name)
        : accountNumber(accNum), balance(bal), accountHolderName(name) {}

    // Function to deposit an amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: Ksh." << balance << "\n";
        } else {
            cout << "Deposit amount must be positive." << "\n";
        }
    }

    // Function to withdraw an amount
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed." << "\n";
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Ksh." << balance << "\n";
        } else {
            cout << "Withdrawal amount must be positive." << "\n";
        }
    }

    // Function to check and display the balance
    void displayBalance() const {
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Current Balance: Ksh." << balance << "\n";
    }
};

int main() {
    // Array to store multiple BankAccount objects
    const int numAccounts = 3;
    BankAccount accounts[numAccounts] = {
        BankAccount(1001, 5000.00, "Stephen"),
        BankAccount(1002, 3000.00, "Birir"),
        BankAccount(1003, 7000.00, "Silas")
    };

    // Display each account's details
    for (int i = 0; i < numAccounts; i++) {
        cout << "\nAccount " << i + 1 << " Details:" << "\n";
        accounts[i].displayBalance();
    }

    // Perform deposit and withdrawal operations
    cout << "\nDepositing Ksh.500 into each account:" << "\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].deposit(500.00);
    }

    cout << "\nWithdrawing Ksh.1000 from each account:" << "\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].withdraw(1000.00);
    }

    // Display each account's details after transactions
    cout << "\nUpdated Account Details:" << "\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].displayBalance();
    }

    return 0;
}
