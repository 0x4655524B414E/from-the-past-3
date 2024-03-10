#pragma once
#include "Account.h"
#include <string>

class Customer
{
private:
	std::string firstName;
	std::string lastName;
	Account *accounts[5]; // composition
	int numberOfAccounts;

public:
	Customer(std::string f, std::string l);
	std::string getFirstName() const;
	std::string getLastName() const;
	Account *operator[](const int &index) const;
	void addAccount(Account *account);
	double getTotalBalance() const;
};
