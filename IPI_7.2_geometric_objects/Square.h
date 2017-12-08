/*
 * Square.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square: public Rectangle {
public:
	Square(double w);
	virtual ~Square();
};

#endif /* SQUARE_H_ */
