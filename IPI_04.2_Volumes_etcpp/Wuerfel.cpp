/*
 * Wuerfel.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#include "Wuerfel.h"
#include <iostream>

Wuerfel::Wuerfel():a(0) {}
Wuerfel::Wuerfel(double a){
	this->a=a;
}
double Wuerfel::surface_area_cube(){
	return (6*a*a);
}
double Wuerfel::volume_cube(){
	return (a*a*a);
}
Wuerfel::~Wuerfel() {
	std::cout<<"Object Cube has been deleted."<<std::endl;
}

