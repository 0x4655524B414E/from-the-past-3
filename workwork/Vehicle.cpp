#include "Vehicle.h"

Vehicle::Vehicle(double max_Load) : maxLoad(kiloToNews(max_Load))
{

}
double Vehicle::getLoad() const
{
	return this->newsToKilo(this->load);
}
double Vehicle::getMaxLoad() const
{
	return this->newsToKilo(this->maxLoad);
}
bool Vehicle::addBox(double weight)
{
	weight = this->kiloToNews(weight);
	if (weight <= 0) return false;
	if (weight + this->load > this->maxLoad) return false;
	this->load += weight;
	return true;
}
double Vehicle::newsToKilo(double weight) const
{
	return weight / 9.8;
}
double Vehicle::kiloToNews(double weight) const
{
	return weight * 9.8;
}


