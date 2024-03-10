#include "Account.h"

Account::Account(double init_balance) : balance(init_balance)
{

}
double Account::getBalance() const
{
	return this->balance;
}
bool Account::deposit(double amount)
{	//policy: can't deposit more than 100'000'000
	if (amount <= 0 || amount > 100'000'000)
	{
		return true;
	}
	this->balance += amount;
	return true;
}
bool Account::withdraw(double amount)
{
	if (amount <= 0 || amount > this->balance)
	{
		return false;
	}
	this->balance -= amount;
	return true;
}
Account Account::operator+(const Account &right) const
{
	return Account(this->balance + right.balance);
}
