/*
 * Sphere.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Sphere.h"
#include <cmath>

Sphere::Sphere(double r):radius(r) {
	if(r<=0) throw std::invalid_argument("Value in Object <=0");
}

Sphere::~Sphere() {}

void Sphere::setRadius(double r){
	this->radius=r;
}

double Sphere::getRadius()const{
	return this->radius;
}

double Sphere::getVolume()const{
	return (4/3)*(M_PI)*(pow(this->radius,3));
}

double Sphere::getSurfaceArea()const{
	return (4*M_PI*pow(radius,2));
}
