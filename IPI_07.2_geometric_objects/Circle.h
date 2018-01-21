/*
 * Circle.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Sphere.h"

/*
 * declaring inheritance private (basically negating it null and manually declare
 * the functionality that you want. -->using Class::function;
 */
class Circle: private Sphere {
public:
	Circle(double r);
	virtual ~Circle();
	using Sphere::getRadius;
	double getArea()const;
	double getCircumference()const;
};

#endif /* CIRCLE_H_ */
