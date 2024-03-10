#pragma once

class Account
{
protected:
	double balance;
public:
	Account(double init_balance = 0.0);
	Account(Account &other);
	double getBalance() const;
	bool deposit(double amount);
	bool withdraw(double amount);
};
