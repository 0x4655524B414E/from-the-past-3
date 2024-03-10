#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Shape
{
private:
	int x, y;

public:
	Shape();
	Shape(double x, double y);
	virtual double area();
};

class PlanarShape : public Shape
{
public:
	PlanarShape();
	PlanarShape(double x, double y);
	virtual double circumference();
};

class VolumetricShape : public Shape
{
private:
	double z;

public:
	VolumetricShape();
	VolumetricShape(double x, double y, double z);
	virtual double volume();
};

class Square : public PlanarShape
{
private:
	double edgeLength;

public:
	Square();
	Square(double x, double y, double edgeLength);
	Square(double x, double y);
	double circumference();
	double area();
};

class Circle : public PlanarShape
{
private:
	double radius;

public:
	Circle();
	Circle(double x, double y, double radius);
	Circle(double x, double y);
	double circumference();
	double area();
};

class Cube : public VolumetricShape
{
private:
	double edgeLength;

public:
	Cube();
	Cube(double x, double y, double z, double edgeLength);
	Cube(double x, double y, double z);
	double volume();
	double area();
};

class Sphere : public VolumetricShape
{
private:
	double radius;

public:
	Sphere();
	Sphere(double x, double y, double z, double edgeLength);
	Sphere(double x, double y, double z);
	double volume();
	double area();
};
