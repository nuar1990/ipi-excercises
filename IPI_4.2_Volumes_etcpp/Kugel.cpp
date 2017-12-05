/*
 * Kugel.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */
#define _USE_MATH_DEFINES

#include "Kugel.h"
#include <math.h>
#include <iostream>

Kugel::Kugel():r(0) {}
Kugel::Kugel(double r){
	this->r=r;
}
double Kugel::surface_area_sphere(){
	return (4*M_PI*r*r);
}
double Kugel::volume_sphere(){
	return (4/3)*(M_PI)*(r*r*r);
}
Kugel::~Kugel() {
	std::cout<<"Object:Sphere has been deleted."<<std::endl;
}

