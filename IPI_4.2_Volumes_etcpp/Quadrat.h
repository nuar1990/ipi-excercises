/*
 * Quadrat.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef QUADRAT_H_
#define QUADRAT_H_

class Quadrat {
private:
	double a;
public:
	Quadrat();
	Quadrat(double);
	double circumference_square();
	double area_square();
	virtual ~Quadrat();
};

#endif /* QUADRAT_H_ */
