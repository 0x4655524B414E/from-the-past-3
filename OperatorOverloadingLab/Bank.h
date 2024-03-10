#pragma once
#include "Customer.h"

class Bank
{
private:
	Customer *customers[10];
	int numberOfCustomers;

public:
	Bank();
	Bank(Bank &other) = delete;
	//Since we delete Copy Constructor, the compiler does not allow the following statement
	//We can delete methods too
	~Bank();
	void addCustomer(const std::string &firstName, const std::string &lastName);
	int getNumberOfCustomers() const;
	Customer *getCustomer(const int &index) const;
};