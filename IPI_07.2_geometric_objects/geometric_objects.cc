/*
 * geometric_objects.cc
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */
#include <iostream>
#include "Circle.h"
#include "Cube.h"
#include "Cuboid.h"
#include <iomanip>
int main(){
	int selector;
	/*
	 * Change Object initialization here
	 */
	Rectangle rectangle=Rectangle(2,3);
	Square	square=Square(4);
	Sphere sphere=Sphere(5);
	Circle circle=Circle(2);
	Cuboid cuboid=Cuboid(2,3,5);
	Cube cube=Cube(4);

	std::cout<<"Welcome to the rudimentary interface to test this exercise:"<<std::endl;
	std::cout<<"Given are the objects:"<<std::endl<<std::endl;
	std::cout<<"Rectangle(length: "<<rectangle.getLength()<<" width: "<<rectangle.getWidth()<<")"<<std::endl;
	std::cout<<"Square(length: "<<square.getLength()<<" width: "<<square.getWidth()<<")"<<std::endl;
	std::cout<<"Sphere(radius : "<<sphere.getRadius()<<")"<<std::endl;
	std::cout<<"Circle(radius : "<<circle.getRadius()<<")"<<std::endl;
	std::cout<<"Cuboid(length: "<<cuboid.getLength()<<" width: "<<cuboid.getWidth()<<" height: "<<cuboid.getHeight()<<")"<<std::endl;
	std::cout<<"Cuboid(length: "<<cube.getLength()<<" width: "<<cube.getWidth()<<" height: "<<cube.getHeight()<<")"<<std::endl;

	while(1) {
		try{
			std::cout<<std::endl;
			std::cout<<"Which object would you like to test: "<<std::endl;
			std::cout<<std::setfill(' ')<<std::setw(15);
			std::cout<<"(1) Rectangle "<<" "<<"(2) Square"<<" "<<"(3) Sphere"<<std::endl;
			std::cout<<std::setfill(' ')<<std::setw(15);
			std::cout<<"(4) Circle "<<" "<<"(5) Cuboid"<<" "<<"(6) Cube"<<std::endl;
			std::cin>>selector;
			if(std::cin.fail()||selector<1||selector>6){
				std::cout<<"Enter a number between [1,6]:"<<std::endl;
				std::cin.clear();
				std::cin.ignore();
				break;
			}
			switch(selector){
			case 1:	std::cout<<"rectangle.width: "<<rectangle.getWidth()<<" rectangle.length: "<<rectangle.getLength()<<std::endl;
					std::cout<<"rectangle.area: "<<rectangle.getArea()<<" rectangle.circumference: "<<rectangle.getCircumference()<<std::endl;
					break;
			case 2:	std::cout<<"square.width: "<<square.getWidth()<<" square.length: "<<square.getWidth()<<std::endl;
					std::cout<<"square.area: "<<square.getArea()<<" square_circumference: "<<square.getCircumference()<<std::endl;
					break;
			case 3:	std::cout<<"sphere.radius: "<<sphere.getRadius()<<std::endl;
					std::cout<<"sphere.surface_area: "<<sphere.getSurfaceArea()<<" sphere_volume: "<<sphere.getVolume()<<std::endl;
					break;
			case 4:	std::cout<<"circle.radius: "<<circle.getRadius()<<std::endl;
					std::cout<<"circle.area: "<<circle.getArea()<<" circle_circumference: "<<circle.getCircumference()<<std::endl;
					break;
			case 5:	std::cout<<"cuboid.width: "<<cuboid.getWidth()<<" cuboid.length: "<<cuboid.getLength()<<" cuboid.height: "<<cuboid.getHeight()<<std::endl;
					std::cout<<"cuboid.surface_area: "<<cuboid.getSurfaceArea()<<" cuboid_volume: "<<cuboid.getVolume()<<std::endl;
					break;
			case 6:	std::cout<<"cube.width: "<<cube.getWidth()<<" cube.length: "<<cube.getWidth()<<" cube.height: "<<cube.getHeight()<<std::endl;
					std::cout<<"cube.surfaceArea: "<<cube.getSurfaceArea()<<" cube_volume: "<<cube.getVolume()<<std::endl;
					break;
			}
			std::cin.clear();
			std::cin.ignore();
			std::cout<<std::endl<<std::endl;
			std::cout<<"Continue? (enter '1')";
			std::cin>>selector;
			if(selector!=1) break;
		}
		catch(const std::exception& e){
			std::cout<<e.what();
		}
	}
	return 0;
}
