/*
 * Rectangle.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <stdexcept>

class Rectangle {
private:
	double width,length;
public:
	Rectangle(double l, double w);
	virtual ~Rectangle();

	void setWidth(double w);
	void setLength(double l);
	double getWidth()const;
	double getLength()const;
	double getArea()const;
	double getCircumference()const;
};

#endif /* RECTANGLE_H_ */
