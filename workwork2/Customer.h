#pragma once
#include "Account.h"
#include <iostream>
using std::string;

class Customer
{
private:
	string firstName;
	string lastName;
	Account *accounts[5];
	int numberOfAccounts;
public:
	Customer(string firstName, string lastName);
	Customer(const Customer &other);
	~Customer();
	string getFirstName() const;
	string getLastName() const;
	Account *getAccount(int index) const;
	void addAccount(Account *account);
};
