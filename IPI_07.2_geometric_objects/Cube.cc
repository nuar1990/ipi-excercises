/*{
 * Cube.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Cube.h"
#include <cmath>

Cube::Cube(double h):Square(h),height(h){
	if(h<=0) throw std::invalid_argument("Value in Object <=0");
}

Cube::~Cube() {}

void Cube::setHeight(double h){
	this->height=h;
}

double Cube::getHeight()const{
	return this->height;
}

double Cube::getVolume()const{
	return height*this->getArea();
}

double Cube::getSurfaceArea()const{
	return this->getCircumference()*1.5*height;
}

