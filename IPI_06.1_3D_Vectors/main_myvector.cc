/*
 *
 * main_myvector.cc
 *
 *  Created on: Dec 1, 2017
 *      Author: nuar
 */
#include <iostream>
#include <math.h>
#include "myvector.h"


int main(){
	std::cout<<"b)"<<std::endl;
	MyVector vectA=MyVector(5,0,2);
	MyVector vectB=MyVector(3,1,4);
	MyVector vectC=MyVector();
	vectC.setValues(5,3,5);
	//vectA=vectA.mult(2);
	//vectB=vectB.mult(2;
	//vectC=vectC.mult(2);
	std::cout<<"generate position vectors:"<<std::endl;
	std::cout<<"vectorA: ";
	vectA.print();
	std::cout<<"vectorB: ";
	vectB.print();
	std::cout<<"vectorC: ";
	vectC.print();
	std::cout<<"--------------------------"<<std::endl;
	/*
	 * Generate vectors forming the triangle
	 */
	std::cout<<"generate vectors spanning the triangle:"<<std::endl;
	MyVector vectAB=vectA.subtract(vectB);
	std::cout<<"vector AB: ";
	vectAB.print();
	MyVector vectBC=vectB.subtract(vectC);
	std::cout<<"vector BC: ";
	vectBC.print();
	MyVector vectAC=vectA.subtract(vectC);
	std::cout<<"vector AC: ";
	vectAC.print();
	std::cout<<"c)"<<std::endl;
	if(vectAB.isOrthogonal(vectBC)||vectAB.isOrthogonal(vectAC)||vectBC.isOrthogonal(vectAC)){
		std::cout<<"The Triangle is rectangular."<<std::endl;
	}
	else{
		std::cout<<"The Triangle isn't rectangular."<<std::endl;
	}
	std::cout<<"-------------------------"<<std::endl;
	std::cout<<"d)"<<std::endl;
	if(	vectAB.angle(vectBC)==vectAB.angle(vectAC)||
		vectAB.angle(vectBC)==vectBC.angle(vectAC)||
		vectAB.angle(vectAC)==vectBC.angle(vectAC)){
		std::cout<<"The triangle is equal-sided"<<std::endl;
	}
	else{
		std::cout<<"The triangle isn't equal-sided"<<std::endl;
	}
	std::cout<<"-------------------------"<<std::endl;
	std::cout<<"e)"<<std::endl;
	/* CAREFUL: It is important to visualize the vector starting points,if the vectors are opposing each other, the angle
	 * calculated is the outer one -->180-angle()  - If chosen correctly this is not necessary however.
	 */
	std::cout<<"Triangle ABC got angles(°): "<<vectAB.angle(vectBC)<<", "<<vectAB.angle(vectAC)<<", "<<vectBC.angle(vectAC)<<std::endl;
	std::cout<<"---------------------"<<std::endl;
	std::cout<<"f)"<<std::endl;
	std::cout<<"Flaecheninhalt A: "<<0.5*vectAB.area(vectAC);
	std::cout<<"----------------------"<<std::endl;
	std::cout<<"g)"<<std::endl;
	std::cout<<"Every multiplication n results in a quadratic A_n=A_0*n^2 increase for the area A."<<std::endl;
	std::cout<<"see lines 19-22";

	return 0;
}
