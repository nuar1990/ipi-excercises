/*
 * Kreis.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef KREIS_H_
#define KREIS_H_

class Kreis {
private:
	double r;
public:
	Kreis();
	Kreis(double);
	double circumference_circle();
	double area_circle();
	virtual ~Kreis();
};

#endif /* KREIS_H_ */
