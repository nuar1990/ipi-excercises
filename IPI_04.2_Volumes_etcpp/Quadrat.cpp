/*
 * Quadrat.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#include "Quadrat.h"
#include <iostream>

Quadrat::Quadrat():a(0) {}
Quadrat::Quadrat(double a){
	this->a=a;
}
double Quadrat::area_square(){
	return (a*a);
}
double Quadrat::circumference_square(){
	return (4*a);
}
Quadrat::~Quadrat() {
	std::cout<<"Object:Square has been deleted."<<std::endl;
}

