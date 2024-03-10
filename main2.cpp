#include "Fraction.h"

int main()
{
	int x = 0;
	x++; // x = x + 1; 
	// pre-increment and post-increment operators
	x++; //post-increment
	++x; // pre-increment
	int w, y = 1;
	w = x++ + y; // w = x + y -> x = x + 1
	w = ++x + y; // x = x + 1 -> w = x + y

	Fraction f1(1,10);
	Fraction f2 = f1++;
	Fraction f3(1,10);
	Fraction f4 = ++f3;

	f1.display();
	f2.display();
	f3.display();
	f4.display();

	Fraction f5 = f4(2,5)(4);
	f5();

	return 0;
}