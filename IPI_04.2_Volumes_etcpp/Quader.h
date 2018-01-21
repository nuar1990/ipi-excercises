/*
 * Quader.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef QUADER_H_
#define QUADER_H_

class Quader {
private:
	double a,b,c;
public:
	Quader();
	Quader(double,double,double);
	double surface_area_cuboid();
	double volume_cuboid();
	virtual ~Quader();
};

#endif /* QUADER_H_ */
