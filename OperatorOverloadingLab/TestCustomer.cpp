#include "Bank.h"
#include <iostream>

int main()
{	
	Account acc1(1'000'000);
	Account acc2(500'000);
	Account acc3 = acc1 + acc2;

	std::cout << acc3.getBalance() << std::endl;
	

	return 0;
}