#include "Shapes.h"

#pragma region Shape Class
Shape::Shape() : Shape(0, 0)
{

}
Shape::Shape(double x, double y) : x(x), y(y)
{

}
double Shape::area()
{
	return 31;
}

#pragma endregion Shape Class	
#pragma region PlanarShape Class
PlanarShape::PlanarShape() : Shape(0, 0)
{

}
PlanarShape::PlanarShape(double x, double y) : Shape(0, 0)
{

}
double PlanarShape::circumference()
{
	return 31;
}
#pragma endregion PlanarShape Class
#pragma region VolumetricShape
VolumetricShape::VolumetricShape() : Shape(0, 0), z(0)
{

}
VolumetricShape::VolumetricShape(double x, double y, double z) : Shape(0, 0), z(z)
{

}
double VolumetricShape::volume()
{
	return 31;
}
#pragma endregion VolumetricShape
#pragma region Square Class
Square::Square() : Square(0, 0, 1)
{

}
Square::Square(double x, double y, double edgeLength) : PlanarShape(x, y), edgeLength(edgeLength)
{

}
Square::Square(double x, double y) : Square(x, y, 1)
{

}
double Square::circumference()
{
	return this->edgeLength * 4.0;
}
double Square::area()
{
	return pow(this->edgeLength, 2);
}
#pragma endregion Square Class
#pragma region Circle Class
Circle::Circle() : Circle(0, 0, 1)
{

}
Circle::Circle(double x, double y, double radius) : PlanarShape(x, y), radius(radius)
{

}
Circle::Circle(double x, double y) : Circle(x, y, 1)
{

}
double Circle::circumference()
{
	return this->radius * 2.0 * M_PI;
}
double Circle::area()
{
	return pow(this->radius, 2) * M_PI;
}
#pragma endregion Circle Class
#pragma region Cube Class
Cube::Cube() : Cube(0, 0, 0, 1)
{

}
Cube::Cube(double x, double y, double z, double edgeLength) : VolumetricShape(x, y, z), edgeLength(edgeLength)
{

}
Cube::Cube(double x, double y, double z) : Cube(x, y, z, 1)
{

}
double Cube::volume()
{
	return pow(this->edgeLength, 3);
}
double Cube::area()
{
	return pow(this->edgeLength, 2) * 6.0;
}
#pragma endregion Cube Class
#pragma region Sphere Class
Sphere::Sphere() : Sphere(0, 0, 0, 1)
{

}
Sphere::Sphere(double x, double y, double z, double radius) : VolumetricShape(x, y, z), radius(radius)
{

}
Sphere::Sphere(double x, double y, double z) : Sphere(x, y, z, 1)
{

}
double Sphere::volume()
{
	return (4.0 / 3.0) * M_PI * pow(this->radius, 3);
}
double Sphere::area()
{
	return 4 * M_PI * pow(this->radius, 2);
}
#pragma endregion Sphere Class
