/*
 * Cuboid.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Cuboid.h"

Cuboid::Cuboid(double w,double h,double l):width(w),height(h),length(l){
	if(w<=0||l<=0||h<=0) throw std::invalid_argument("Value in Object <=0");
}

Cuboid::~Cuboid() {}

void Cuboid::setWidth(double w){
	this->width=w;
}

void Cuboid::setHeight(double h){
	this->height=h;
}

void Cuboid::setLength(double l){
	this->length=l;
}

double Cuboid::getWidth()const{
	return this->width;
}

double Cuboid::getHeight()const{
	return this->height;
}

double Cuboid::getLength()const{
	return this->length;
}

double Cuboid::getSurfaceArea()const{
	return 2*(length*width+length*height+width*height);
}
double Cuboid::getVolume()const{
	return (length*width*height);
}
