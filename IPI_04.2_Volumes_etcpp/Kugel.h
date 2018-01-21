/*
 * Kugel.h
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#ifndef KUGEL_H_
#define KUGEL_H_

class Kugel {
private:
	double r;
public:
	Kugel();
	Kugel(double);
	double surface_area_sphere();
	double volume_sphere();
	virtual ~Kugel();
};

#endif /* KUGEL_H_ */
