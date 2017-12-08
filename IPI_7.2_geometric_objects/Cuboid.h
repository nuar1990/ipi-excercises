/*
 * Cuboid.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef CUBOID_H_
#define CUBOID_H_

#include <stdexcept>

class Cuboid {
private:
	double width, height, length;
public:
	Cuboid(double w, double h, double l);
	virtual ~Cuboid();
	void setWidth(double w);
	void setHeight(double h);
	void setLength(double l);
	double getWidth()const;
	double getHeight()const;
	double getLength()const;
	double getSurfaceArea()const;
	double getVolume()const;
};

#endif /* CUBOID_H_ */
