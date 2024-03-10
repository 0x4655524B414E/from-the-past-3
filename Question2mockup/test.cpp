#include <iostream>
#include "Shapes.h"

int main()
{	
	Square x(2,3);
	Sphere a(0,0,0,12);

	std::cout << a.area() << std::endl;
	std::cout << a.volume() << std::endl;

	return 0;
}