#include "Account.h"
#pragma once

class CheckingAccount : public Account
{
private:
	double overdraftProtection;
public:
	CheckingAccount(double balance);
	CheckingAccount(double balance, double protect);
	bool withdraw(double amount);
};
