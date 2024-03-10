#pragma once
using namespace std;
#include <ostream>

class Account
{
private:
	double balance;

public:
	Account(double init_balance);

	double getBalance() const;

	bool deposit(double amount);
	bool withdraw(double amount);
	Account operator+(const Account &right) const;
	friend ostream& operator<<(ostream &os, const Account &account);


};
ostream& operator<<(ostream &os, const Account &account)
{
	   os << "Account [ "
	   << "balance: "
	   << account.balance
	   << " ]"
	   << std::endl;
	return os;
}