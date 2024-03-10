#include "Customer.h"

Customer::Customer(string firstName, string lastName)
 : firstName(firstName), lastName(lastName), numberOfAccounts(0)
{
	for (int i = 0; i < 5; i++)
	{
		this->accounts[i] = nullptr;
	}
}
Customer::Customer(const Customer &other)
{
	this->numberOfAccounts = other.numberOfAccounts;
	for (int i = 0; i < this->numberOfAccounts; i++)
	{
		this->accounts[i] = new Account(*other.accounts[i]);
	}
}
Customer::~Customer()
{
	for (int i = 0; i < this->numberOfAccounts; i++)
	{
		delete this->accounts[i];
	}
}
string Customer::getFirstName() const
{
	return this->firstName;
}
string Customer::getLastName() const
{
	return this->lastName;
}
Account *Customer::getAccount(int index) const
{
	if (index < 0 || index >= this->numberOfAccounts) return nullptr;
	return this->accounts[index];
}
void Customer::addAccount(Account *account)
{
	if (account == nullptr) return;
	if (this->numberOfAccounts >= 5) return;
	this->accounts[this->numberOfAccounts] = account;
	this->numberOfAccounts++;
}