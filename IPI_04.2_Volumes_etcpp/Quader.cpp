/*
 * Quader.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#include "Quader.h"
#include <iostream>

Quader::Quader():a(0),b(0),c(0) {}

Quader::Quader(double a, double b, double c){
	this->a=a;
	this->b=b;
	this->c=c;
}
double Quader::surface_area_cuboid(){
	return (2*a*c)+(2*a*c)+(2*b*c);
}
double Quader::volume_cuboid(){
	return (a*b*c);
}
Quader::~Quader() {
	std::cout<<"Object:Cuboid has been deleted."<<std::endl;
}

