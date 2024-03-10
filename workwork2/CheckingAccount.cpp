#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double balance) : Account(balance)
{

}
CheckingAccount::CheckingAccount(double balance, double protect) : Account(balance), overdraftProtection(protect)
{

}
bool CheckingAccount::withdraw(double amount)
{
	if (amount <= 0) return false;
	if (amount > this->balance + this->overdraftProtection) return false;
	this->balance -=balance;
	return true;
}