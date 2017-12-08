/*
 * Circle.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Circle.h"
#include <cmath>

Circle::Circle(double r):Sphere(r) {
	if(r<=0) throw std::invalid_argument("Value in Object <=0");
}

Circle::~Circle() {}

double Circle::getArea()const{
	return (M_PI * pow(this->getRadius(),2));
}

double Circle::getCircumference()const{
	return(2*M_PI*this->getRadius());
}
