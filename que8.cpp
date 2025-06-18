#include <iostream>
#include <vector>
using namespace std;

// Base class
class BankAccount {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNo, double bal) {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited: " << amount << endl;
        } else {
            cout << "Invalid Deposit Amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient Balance." << endl;
        }
    }

    virtual void showDetails() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class (Inheritance)
class Admin : public BankAccount {
public:
    Admin(string name, int accNo, double bal) : BankAccount(name, accNo, bal) {}

    void showDetails() override {
        cout << "[Admin View] ";
        BankAccount::showDetails();
    }

    void resetBalance() {
        balance = 0;
        cout << "Balance has been reset to 0.\n";
    }
};

// Main system to manage multiple accounts
class BankSystem {
private:
    vector<BankAccount*> accounts;

public:
    void addAccount(BankAccount* acc) {
        accounts.push_back(acc);
    }

    void displayAllAccounts() {
        for (auto acc : accounts) {
            acc->showDetails();
            cout << "---------------------\n";
        }
    }

    ~BankSystem() {
        for (auto acc : accounts)
            delete acc;
    }
};

int main() {
    BankSystem bank;

    // Creating accounts (Encapsulation)
    BankAccount* user1 = new BankAccount("Vishal", 1001, 5000);
    Admin* admin1 = new Admin("AdminV", 9999, 100000);

    // Operations
    user1->deposit(1500);
    user1->withdraw(2000);
    admin1->resetBalance();

    // Add accounts to bank system
    bank.addAccount(user1);
    bank.addAccount(admin1);

    // Display all accounts (Polymorphism)
    cout << "\n=== All Bank Accounts ===\n";
    bank.displayAllAccounts();

    return 0;
}
