#include "Bank.h"

Bank::Bank() : numberOfCustomers(0)
{
	for (int i = 0; i < 10; i++)
	{
		this->customers[i] = nullptr;
	}
}
Bank::Bank(const Bank &other)
{
	this->numberOfCustomers = other.numberOfCustomers;
	for (int i = 0; i < this->numberOfCustomers; i++)
	{
		this->customers[i] = new Customer(*other.customers[i]);
	}
}
Bank::~Bank()
{
	for (int i = 0; i < this->numberOfCustomers; i++)
	{
		delete this->customers[i];
	}
}
void Bank::addCustomer(string firstName, string lastName)
{
	if (this->numberOfCustomers >= 10) return;
	this->customers[this->numberOfCustomers] = new Customer(firstName, lastName);	
	this->numberOfCustomers++;
}
int Bank::getNumberOfCustomers() const
{
	return this->numberOfCustomers;
}
Customer *Bank::getCustomer(int index) const
{
	if (index < 0 || this->numberOfCustomers <= index) return nullptr;
	return this->customers[index];
}