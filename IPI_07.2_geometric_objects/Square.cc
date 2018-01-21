/*
 * Square.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#include "Square.h"

Square::Square(double w):Rectangle(w,w){
	if(w<=0) throw std::invalid_argument("Value in Object <=0");
}

Square::~Square() {}

