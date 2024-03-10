#pragma once
#include "Customer.h"

class Bank
{
private:
	Customer *customers[10];
	int numberOfCustomers;
public:
	Bank();
	Bank(const Bank &other);
	~Bank();
	void addCustomer(string firstName, string lastName);
	int getNumberOfCustomers() const;
	Customer *getCustomer(int index) const;
};
