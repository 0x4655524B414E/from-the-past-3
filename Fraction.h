#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator);
	int get_numerator() const;
	int get_denominator() const;
	void display() const;
	Fraction add(const Fraction &second);
	Fraction operator+(const Fraction &second);
	Fraction operator*(const Fraction &second);
	Fraction operator-(const Fraction &second);
	Fraction operator-();
	Fraction operator/(const Fraction &second);
	Fraction operator=(const Fraction &right);
	Fraction operator++(); // pre-increment
	Fraction operator++(int); // post-increment
	Fraction operator()(int,int);
	Fraction operator()(int);
	void operator()();
};
