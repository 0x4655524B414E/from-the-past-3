#include "Fraction.h"
#include <iostream>


int main()
{
	Fraction f1(2,3);
	Fraction f2(1,3);
	
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1 + f2;
	Fraction f5 = f1 - f2;
	Fraction f6 = f1 * f2;
	Fraction f7 = f1 / f2;
	Fraction f8 = -f1;

	f3.display();
	f4.display();
	f5.display();
	f6.display();
	f7.display();
	f8.display();

	f8 = f1 - f2;
	f8 = f2 = f3; // we can chain '=' because now we are returning a value type
	f8.display();

	return 0;
}