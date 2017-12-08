/*
 * Cube.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Square.h"

class Cube: public Square {
private:
	double height;
public:
	Cube(double h);
	virtual ~Cube();
	void setHeight(double h);
	double getHeight()const;
	double getVolume()const;
	double getSurfaceArea()const;
};

#endif /* CUBE_H_ */
