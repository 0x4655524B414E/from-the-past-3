#include "smith.h"
#include <iostream>

int main()
{
	for (unsigned i = 2; i < 1001; i++)
	{
		if (isSmithNum(i))
		{
			std::cout << i << ", ";
		}
	}
	
	return 0;
}

