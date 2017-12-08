/*
 * Sphere.h
 *
 *  Created on: Dec 7, 2017
 *      Author: nuar
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <stdexcept>
class Sphere {
private:
	double radius;
public:
	Sphere(double r);
	virtual ~Sphere();
	void setRadius(double r);
	/*
			 * d) These are methods that exclusively match a Sphere Object, therefore
			 * these should not be known to class Circle.
			 * Contrary to b, where Square is just a specific case of a rectangle.
			 * Therefore the inherition must be declared private.
			 * !!! This is considered very bad practice,
			 * why have a children class that doesn't feature the same behaviour as the parent?
			 * anyway here is how it's done: Important to NOT declare Circle a friend, see 7.1
	    */
	double getRadius()const;
	double getVolume()const;
	double getSurfaceArea()const;
};

#endif /* SPHERE_H_ */
