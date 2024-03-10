#pragma once

class Vehicle
{
private:
	double load;
	double maxLoad;
	double newsToKilo(double weight) const;
	double kiloToNews(double weight) const;
public:
	Vehicle(double max_Load);
	double getLoad() const;
	double getMaxLoad() const;
	bool addBox(double weight);
};
