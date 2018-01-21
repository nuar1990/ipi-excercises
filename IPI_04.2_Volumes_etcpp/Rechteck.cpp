/*
 * Rechteck.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#include "Rechteck.h"
#include <iostream>

Rechteck::Rechteck():a(0),b(0){}
Rechteck::Rechteck(double a,double b){
	this->a=a;
	this->b=b;
}
double Rechteck::circumference_rectangle(){
	return (2*a+2*b);
}
double Rechteck::area_rectangle(){
	return (a*b);
}
Rechteck::~Rechteck() {
	std::cout<<"Object Rectangle has been deleted."<<std::endl;
}

