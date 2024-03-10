#include "Customer.h"

Customer::Customer(std::string f, std::string l) : firstName(f), lastName(l)
{
	this->numberOfAccounts = 0;
	for (Account *&account : this->accounts)
	{
		account = nullptr;	
	}
}
std::string Customer::getFirstName() const
{
	return this->firstName;
}
std::string Customer::getLastName() const
{
	return this->lastName;	
}
Account *Customer::operator[](const int &index) const
{
	if (index < 0 || index >= this->numberOfAccounts) return nullptr;
	return this->accounts[index];
}
void Customer::addAccount(Account *account)
{
	if (this->numberOfAccounts == 5) return;
	if (account == nullptr) return;
	this->accounts[this->numberOfAccounts] = account;
	this->numberOfAccounts++;
}
double Customer::getTotalBalance() const
{
	double sum {0};
	for (Account *account : accounts)
	{
		if (account == nullptr) break;
		sum += account->getBalance();
	}
	return sum;
}

