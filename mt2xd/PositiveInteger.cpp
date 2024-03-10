#include "PositiveInteger.h"

PositiveInteger::PositiveInteger(int num) : Number(), hold(num)
{

}
int PositiveInteger::toInteger() const
{
	return this->hold;
}
Number *PositiveInteger::operator++(int)
{
	this->hold = this->hold + 1;
	return this;
}
Number *PositiveInteger::operator--(int)
{
	if (this->hold <= 0)
	{
		this->hold = 0;
		return this;
	}
	this->hold = this->hold - 1;
	return this;
}
