#include "Bank.h"

Bank::Bank()
{
	this->numberOfCustomers = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	this->customers[i] = nullptr;
	//}
	for (Customer *&customer : customers)
	{
		customer = nullptr;
	}
}
//Bank::Bank(Bank &other)
//{
//	this->numberOfCustomers = other.numberOfCustomers;
//	for (int i = 0; i < this->numberOfCustomers; i++)
//	{
//		Customer *customer = other.customers[i];
//		this->customers[i] = new Customer(customer->getFirstName(), customer->getLastName());
//	}
//}
Bank::~Bank()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	this->customers[i] = nullptr;
	//}
	for (Customer *&customer : customers)
	{
		delete customer;
	}
}
void Bank::addCustomer(const std::string &firstName, const std::string &lastName)
{
	if (this->numberOfCustomers >= 10) return;
	this->customers[this->numberOfCustomers] = new Customer(firstName, lastName);
	this->numberOfCustomers++;
}
int Bank::getNumberOfCustomers() const
{
	return this->numberOfCustomers;
}
Customer *Bank::getCustomer(const int &index) const
{
	if (this->numberOfCustomers == 0 || index < 0 || index >= this->numberOfCustomers) return nullptr;
	return this->customers[index];
}

