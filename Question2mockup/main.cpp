#include "Shapes.h"
#include <iostream>
using std::cout, std::endl;

int main(){
	PlanarShape *planar[]=
	{
 		new Circle() , //unit circle at (0,0)
 		new Square(), // unit square, top-left corner at (0,0)
 		new Circle(4,8), // unit circle at (4,8)
 		new Square(15,16), // unit square, top-left corner at (15,16)
 		new Circle(23,42,108), // circle at (23,42), radius is 108
 		new Square(4,8,15) // top-left corner at (4,8), edge length is 1
 	};
	int lengthOfPlanar= sizeof(planar)/sizeof(PlanarShape*);

 	for (int i=0;i<lengthOfPlanar;++i)
 		cout << "Circumference of " << i << "th planar shape is "
 		 	 << planar[i]->circumference() << endl;

	VolumetricShape *volumetric[]=
 	{
 		new Sphere() , //unit sphere at the origin
 		new Cube(), // unit cube, top-left-rear corner is at the origin
		new Sphere(4,8,15), // unit sphere at (4,8,15)
		new Cube(16,23,42), // unit cube, top-left-rear corner at (16,23,42)
		new Sphere(16,23,42,108), // sphere at (16,23,42), radius is 108
		new Cube(4,8,15,16) // top-left-rear corner at (4,8,15), edge length is 16
	};

	int lengthOfVolumetric= sizeof(volumetric)/sizeof(VolumetricShape*);

 	for (int i=0;i<lengthOfVolumetric;++i)
 		cout << "Volume of " << i << "th volumetric shape is "
 			 << volumetric[i]->volume() << endl ;

	Shape **shapes;
	int lengthOfShapes=lengthOfPlanar+lengthOfVolumetric;
	shapes= new Shape*[lengthOfShapes];

	for (int i=0;i<lengthOfPlanar;++i)
	shapes[i]=planar[i];
	
	for (int i=0,j=lengthOfPlanar;i<lengthOfVolumetric;++i,++j)
	shapes[j]=volumetric[i];
	
	for (int i=0;i<lengthOfShapes;++i)
	cout << "Area of " << i << "th shape is " << shapes[i]->area() << endl ;
	
	for (int i=0;i<lengthOfPlanar;++i)
	
	delete planar[i];
	
	for (int i=0;i<lengthOfVolumetric;++i)
	delete volumetric[i];

	delete []shapes;
 	return 0;
}