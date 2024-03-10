#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
{
	
}
int Fraction::get_denominator() const
{
	return this->denominator;
}
int Fraction::get_numerator() const 
{
	return this->numerator;
}
void Fraction::display() const
{
	std::cout << this->numerator << "/" << this->denominator << std::endl;
}
Fraction Fraction::add(const Fraction &second)
{
	int x = this->numerator * second.denominator + second.numerator * this->denominator;
	int y = this->denominator * second.denominator;
	return Fraction(x, y);
}
Fraction Fraction::operator+(const Fraction &second)
{
	int x = this->numerator * second.denominator + second.numerator * this->denominator;
	int y = this->denominator * second.denominator;
	return Fraction(x, y);
}
Fraction Fraction::operator-(const Fraction &second) // binary operator
{
	int x = this->numerator * second.denominator - second.numerator * this->denominator;
	int y = this->denominator * second.denominator;
	return Fraction(x, y);
}
Fraction Fraction::operator-() // unary operator
{
	return Fraction(-this->numerator, this->denominator);
}
Fraction Fraction::operator*(const Fraction &second)
{
	int x = this->numerator * second.numerator;
	int y =	this->denominator * second.denominator;
	return Fraction(x, y);
}
Fraction Fraction::operator/(const Fraction &second)
{
	int x = this->numerator * second.denominator;
	int y = this->denominator * second.numerator;
	return Fraction(x, y);
}
Fraction Fraction::operator=(const Fraction &right)
{
	this->denominator = right.denominator;
	this->numerator = right.numerator;
	return *this;
}
Fraction Fraction::operator++() // pre-increment
{
	this->numerator += this->denominator;
	return *this;
}
Fraction Fraction::operator++(int) // post-increment
{
	int x = this->numerator;
	int y = this->denominator;
	this->numerator = this->numerator + this->denominator;
	return Fraction(x, y);
}
Fraction Fraction::operator()(int p,int q)
{
	int x = this->numerator + p;
	int y = this->denominator + q;
	return Fraction(x, y);
}
Fraction Fraction::operator()(int s)
{
	int x = this->numerator * s;
	int y = this->denominator * s;
	return Fraction(x, y);
}
void Fraction::operator()()
{
	this->display();
}
