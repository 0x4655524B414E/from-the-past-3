#include "Account.h"

Account::Account(double init_balance) : balance(init_balance)
{

}
Account::Account(Account &other)
{
	this->balance = other.balance;
}
double Account::getBalance() const
{
	return this->balance;
}
bool Account::deposit(double amount)
{
	if (amount <= 0) return false;
	this->balance += amount;
	return true;
}
bool Account::withdraw(double amount)
{
	if (amount <= 0) return false;
	if (amount > balance) return false;
	this->balance -= amount;
	return true;
}
