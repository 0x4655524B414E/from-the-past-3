#include "Bool.h"

Bool::Bool(int num) : Number() ,hold(num)
{

}
int Bool::toInteger() const
{
	return this->hold;
}
Number *Bool::operator++(int)
{
	if (this->hold == 1)
	{
		this->hold = 0;
		return this;
	}
	this->hold = 1;
	return this;
}
Number *Bool::operator--(int)
{
	if (this->hold == 0)
	{
		this->hold = 1;
		return this;
	}
	this->hold == 0;
	return this;
}
