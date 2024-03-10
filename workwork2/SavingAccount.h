#include "Account.h"
#pragma once

class SavingAccount : public Account
{
private:
	double interestRate;
public:
	SavingAccount(double balance, double interest_rate);
};
