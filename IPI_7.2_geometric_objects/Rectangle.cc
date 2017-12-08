/*
 * Rectangle.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Rectangle.h"

Rectangle::Rectangle(double l, double w):width(w),length(l) {
	if(w<=0||l<=0) throw std::invalid_argument("Value in Object <=0");
}

Rectangle::~Rectangle() {}

void Rectangle::setWidth(double w){
	this->width=w;
}

void Rectangle::setLength(double l){
	this->length=l;
}

double Rectangle::getWidth() const{
	return this->width;
}

double Rectangle::getLength()const{
	return this->length;
}

double Rectangle::getArea()const{
	return this->length*this->width;
}

double Rectangle::getCircumference()const{
	return 2*(this->length+this->width);
}
