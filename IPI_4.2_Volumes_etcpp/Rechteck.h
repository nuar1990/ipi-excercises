/*
 * Rechteck.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef RECHTECK_H_
#define RECHTECK_H_

class Rechteck {
private:
	double a,b;
public:
	Rechteck();
	Rechteck(double,double);
	double circumference_rectangle();
	double area_rectangle();
	virtual ~Rechteck();
};

#endif /* RECHTECK_H_ */
