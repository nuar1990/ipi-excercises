/*
 * Wuerfel.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef WUERFEL_H_
#define WUERFEL_H_

class Wuerfel {
private:
	double a;
public:
	Wuerfel();
	Wuerfel(double);
	double surface_area_cube();
	double volume_cube();
	virtual ~Wuerfel();
};

#endif /* WUERFEL_H_ */
