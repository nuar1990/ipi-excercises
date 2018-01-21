/*
 * main_errorvalue.cc
 *
 *  Created on: Dec 2, 2017
 *      Author: nuar
 */
#include <iostream>
#include "errorvalue.h"

int main(){
	ErrorValue a(10.0,2.0), b(5.0,1.0);
	ErrorValue s=a+b;
	std::cout<<"a)"<<std::endl;
	std::cout<<s.value()<<" +/- "<<s.absolute()<<" ("<<s.relative()*100<<" %)"<<std::endl;

	double listA[8]={10.0,10.2,10.8,10.1,9.6,10.2,9.9,10.3};
	double listB[10]={14.2,15.0,13.8,14.5,14.8,14.5,13.9,14.1,14.5,14.2};
	double listC[9]	={11.3,10.8,11.1,11.0,11.6,10.8,10.7,11.8,12.0};

	ErrorValue A=ErrorValue();
	ErrorValue B=ErrorValue();
	ErrorValue C=ErrorValue();
	ErrorValue D=ErrorValue();
	A=A.fromMeasurements(listA,8);
	B=B.fromMeasurements(listB,10);
	C=C.fromMeasurements(listC,9);
	D=A+B+C;

	std::cout<<"b)+c)"<<std::endl;
	std::cout<<"A: "<<A.value()<<" +/- "<<A.absolute()<<" ("<<A.relative()*100<<" %)"<<std::endl;
	std::cout<<"B: "<<B.value()<<" +/- "<<B.absolute()<<" ("<<B.relative()*100<<" %)"<<std::endl;
	std::cout<<"C: "<<C.value()<<" +/- "<<C.absolute()<<" ("<<C.relative()*100<<" %)"<<std::endl;
	std::cout<<"D: "<<D.value()<<" +/- "<<D.absolute()<<" ("<<D.relative()*100<<" %)"<<std::endl;
}
