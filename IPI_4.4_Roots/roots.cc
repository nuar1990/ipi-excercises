/*
 * roots.cc
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */

#include <iostream>
#include <limits>
#include <cmath>

typedef std::numeric_limits< double > dbl;

double newton_method(double c);
double bisection_method(double c);


int main(int argc, char *argv[]){
	std::cout.precision(dbl::max_digits10+2);
	double c;
	std::cout<<"Enter number to take root of:";
	std::cin>>c;
	if(std::cin.fail()||c<0){
		std::cout<<"Not a valid entry."<<std::endl;
		return 0;
	}
	//b)
	double newton=newton_method(c);
	std::cout<<"----------------------------------------------------"<<std::endl;
	//c)
	double bisection=bisection_method(c);
	std::cout<<"----------------------------------------------------"<<std::endl;
	//d)
	std::cout<<"Newton: "<<newton<<"     Bisection: "<<bisection<<std::endl;
	return 0;
}

//f(x)=1-c/x^2 f'(x)=2c/x^3 somit: x_n+1= x_n-[	((1-c)/(x²_n))	/	((2c)/(x³_n))	]
//Alt.: f(x)=x^2-c, f'(x)=2x somit: x_n+1= x_n-[ (x²_n-c)/ 2x_n ]
double newton_method(double c){

	double x=4;//d)
	//double x=c;
	double compare=0;

	unsigned int k=0;
	//Abbruchkriterium x_(k+1)-x_(k)<0.00001
	while(std::abs(x-compare)>0.0000000000001){
		std::cout<<"k:"<<k<<"   x_k:"<<x<<std::endl;
		//Wenn Zahl genau bestimmt, oder Steigung=0
		if(c==x*x || 2*x==0){
			break;
		}
		compare=x;
		//x=x-((1-(c/(x*x)))	/	((2*c)/x*x*x)	);
		x=x-(((x*x)-c)/(2*x));
		k++;
	}
	return x;
}
double bisection_method(double c){
	double a=0;
	double b=4;//d
	//double b=c;
	double m=(a+b)/2; //average
	double compare=0;

	unsigned int k=0;
	//Abbruchkriterium x_(k+1)-x_(k)<0.n
	while(std::abs(m-compare)>0.0000000000001){
		std::cout<<"k:"<<k<<"   x_k:"<<m<<std::endl;
		if((m*m)<c){
			a=m;
		}
		if((m*m)>c){
			b=m;
		}
		if((m*m)==c){
			break;
		}
		compare=m;
		m=(a+b)/2;
		k++;
	}
	return m;
}
