#include "Integer.h"
#include "Number.h"

Integer::Integer(int num) : Number(), hold(num)
{

}
int Integer::toInteger() const
{
	return this->hold;
}
Number *Integer::operator++(int)
{
	this->hold = this->hold + 1;
	return this;
}
Number *Integer::operator--(int)
{
	this->hold = this->hold - 1;
	return this;
}