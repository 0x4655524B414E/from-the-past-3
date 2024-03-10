#include "smith.h"

unsigned sumOfDigits(unsigned num)
{
	unsigned sum {0};
	while (num >= 10)
	{
		sum += num % 10;
		num /= 10;
	}
	sum += num;
	return sum;
}
unsigned sumOfDigits(const std::vector <unsigned> &vector)
{
	unsigned sum {0};
	for (auto &&i : vector)
	{
		sum += sumOfDigits(i);
	}
	return sum;
}
std::vector <unsigned> primeFactorsVector(unsigned num)
{
	std::vector <unsigned> vector;
	for (unsigned i = 2; i <= num; i++)
	{
		while (num % i == 0)
		{
			vector.push_back(i);
			num /= i;
		}
	}
	return vector;	
}
bool isSmithNum(unsigned num)
{
	if (sumOfDigits(num) == sumOfDigits(primeFactorsVector(num)) && !isPrime(num))
	{
		return true;
	}
	return false;
}
bool isPrime(unsigned num)
{
	if (num > 1)
	{
		unsigned count {2};
		while (count <= num/2)
		{
			if (num % count == 0)
			{
				return false;
			}
			count++;
		}
		return true;	
	}
	return false;
}