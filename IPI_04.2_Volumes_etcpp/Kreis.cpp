/*
 * Kreis.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */
#define _USE_MATH_DEFINES

#include "Kreis.h"
#include <math.h>
#include <iostream>

Kreis::Kreis():r(0) {}

Kreis::Kreis(double r){
	this->r=r;
}
double Kreis::circumference_circle(){
	return(2*M_PI*r);
}
double Kreis::area_circle(){
	return (M_PI * r*r);
}
Kreis::~Kreis() {
	std::cout<<"Object:Circle has been deleted."<<std::endl;
}

