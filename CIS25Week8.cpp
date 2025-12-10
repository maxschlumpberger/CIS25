// CIS25Week8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class BankAccount {
private:
    string accountName;
    double balance;



    void logTransaction(string transactionType, string transactionDescription, double amount) {
        ofstream file("account_log.txt", ios::app);

        if (file.is_open()) {
            file << transactionType << ": $" << amount << " | Description: " << transactionDescription << " | Balance: $" << balance << endl;
            file.close();
        }
    }


public:
    BankAccount(string name, double firstBalance) {
        
        balance = firstBalance;
        accountName = name;

        logTransaction("Account creation.", "Initial balance.", firstBalance);
    }

    void purchase(double amount, string purchaseItem) {
        if (amount <= 0) {
            cout << "You cannot make a purchase for 0 or less dollars. Please try again." << endl;
            logTransaction("Purchase error.", "Bad purchase", amount);
        }
        else if (amount > balance) {
            cout << "Your purchase cannot exceed your current balance. Please try again." << endl;
            logTransaction("Purchase error.","Insufficient funds", amount);
        }
        else {
            balance -= amount;
            cout << "Your purchase is complete. Your remaining balance is $" << balance << "." << endl;
            logTransaction("Purchase successful.", "You have purchased " + purchaseItem, amount);
        }
    }

    void deposit(double amount, string depositType) {
        if (amount <= 0) {
            cout << "You cannot make a deposit for 0 or less dollars. Please try again." << endl;
            logTransaction("Deposit error.", "Bad deposit", amount);
        }
        else {
            balance += amount;
            cout << "Your deposit is complete. Your new balance is $" << balance << "." << endl;
            logTransaction("Deposit successful.", depositType, amount);
        }
    }

    void printBalance() {
        cout << "Your current balance is: $" << balance << endl;
        
    }

};



int main() {
    
    BankAccount testAccount("George Fredley", 0.00);

    testAccount.deposit(10000.00, "Monthly Paycheck");
    testAccount.purchase(35.99, "Novel");
    testAccount.purchase(22.99, "Chicken Alfredo");

    testAccount.printBalance();

    return 0;
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
