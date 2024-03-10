/* 
 * File:   TestBanking.cpp
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 8:06 PM
 */

#include <iostream>
using namespace std;
#include "Account.h"
#include "Customer.h"
#include "Bank.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Bank *bank = new Bank();
    Customer *customer;
    Account *account;

    //
    // Create bank customers and their accounts
    //

    cout << endl << "Creating the customer Jane Smith.";
    bank->addCustomer("Jane", "Simms");
    customer = bank->getCustomer(0);
    cout << endl << "Creating her Savings Account with a 500.00 balance and 3% interest.";
    customer->addAccount(new SavingAccount(500.00, 0.03));

    cout << endl << "Creating the customer Owen Bryant.";
    bank->addCustomer("Owen", "Bryant");
    customer = bank->getCustomer(1);
    cout << endl << "Creating his Checking Account with a 500.00 balance and no overdraft protection.";
    customer->addAccount(new CheckingAccount(500.00));

    cout << endl << "Creating the customer Tim Soley.";
    bank->addCustomer("Tim", "Soley");
    customer = bank->getCustomer(2);
    cout << endl << "Creating his Checking Account with a 500.00 balance and 500.00 in overdraft protection.";
    customer->addAccount(new CheckingAccount(500.00, 500.00));

    cout << endl << "Creating the customer Maria Soley.";
    bank->addCustomer("Maria", "Soley");
    customer = bank->getCustomer(3);
    cout << endl << "Maria shares her Checking Account with her husband Tim.";
    customer->addAccount(bank->getCustomer(2)->getAccount(0));

    cout << endl ;

    //
    // Demonstrate behavior of various account types
    //

    // Test a standard Savings Account
    cout << endl << "Retrieving the customer Jane Smith with her savings account.";
    customer = bank->getCustomer(0);
    account = customer->getAccount(0);
    // Perform some account transactions
    cout << endl << "Withdraw 150.00: " << account->withdraw(150.00);
    cout << endl << "Deposit 22.50: " << account->deposit(22.50);
    cout << endl << "Withdraw 47.62: " << account->withdraw(47.62);
    cout << endl << "Withdraw 400.00: " << account->withdraw(400.00);
    // Print out the final account balance
    cout << endl << "Customer [" + customer->getLastName()
		       + ", " + customer->getFirstName()
		       + "] has a balance of " << account->getBalance();

    cout << endl ;

    // Test a Checking Account w/o overdraft protection
    cout << endl << "Retrieving the customer Owen Bryant with his checking account with no overdraft protection.";
    customer = bank->getCustomer(1);
    account = customer->getAccount(0);
    // Perform some account transactions
    cout << endl << "Withdraw 150.00: " << account->withdraw(150.00);
    cout << endl << "Deposit 22.50: " << account->deposit(22.50);
    cout << endl << "Withdraw 47.62: " << account->withdraw(47.62);
    cout << endl << "Withdraw 400.00: " << account->withdraw(400.00);
    // Print out the final account balance
    cout << endl << "Customer [" << customer->getLastName()
		       << ", " << customer->getFirstName()
		       << "] has a balance of " << account->getBalance();

    cout << endl ;

    // Test a Checking Account with overdraft protection
    cout << endl << "Retrieving the customer Tim Soley with his checking account that has overdraft protection.";
    customer = bank->getCustomer(2);
    account = customer->getAccount(0);
    // Perform some account transactions
    cout << endl << "Withdraw 150.00: " << account->withdraw(150.00);
    cout << endl << "Deposit 22.50: " << account->deposit(22.50);
    cout << endl << "Withdraw 47.62: " << account->withdraw(47.62);
    cout << endl << "Withdraw 400.00: " << account->withdraw(400.00);
    // Print out the final account balance
    cout << endl << "Customer [" << customer->getLastName()
		       << ", " << customer->getFirstName()
		       << "] has a balance of " << account->getBalance();

    cout << endl ;

    // Test a Checking Account with overdraft protection
    cout << endl << "Retrieving the customer Maria Soley with her joint checking account with husband Tim.";
    customer = bank->getCustomer(3);
    account = customer->getAccount(0);
    // Perform some account transactions
    cout << endl << "Deposit 150.00: " << account->deposit(150.00);
    cout << endl << "Withdraw 750.00: " << account->withdraw(750.00);
    // Print out the final account balance
    cout << endl << "Customer [" << customer->getLastName()
		       << ", " << customer->getFirstName()
		       << "] has a balance of " 
                       << account->getBalance()
                       << endl ;
    for (int i=0;i<bank->getNumberOfCustomers();++i){
        delete bank->getCustomer(i);
    }
    delete bank;
    return (EXIT_SUCCESS);
}

