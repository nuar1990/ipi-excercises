/*
 * roots.cc
 *
 *  Created on: Nov 18, 2017
 *      Author: nuar
 */
#include <iostream>
#include <math.h>

int number_of_solutions(double a,double b,double c);
double calc_one_solution(double a,double b, double c);
double calc_two_solution_plus(double a,double b, double c);
double calc_two_solution_minus(double a,double b, double c);

int main(int argc, char *argv[]){
	double a,b,c;
	int solutions;

	try{
		std::cout<<"Enter a,b,c of the quadratic equation: ax^2+bx+c=0"<<std::endl;
		std::cout<<"a:";
		std::cin>>a;
		std::cout<<"b:";
		std::cin>>b;
		std::cout<<"c:";
		std::cin>>c;
		if(std::cin.fail()){
			std::cout<<"Not a valid entry, closing program."<<std::endl;
			return 0;
		}
		if(a==0){
			throw(0);
		}
		solutions=number_of_solutions(a,b,c);
		if(solutions==1){
			std::cout<<"One Solution:"<<std::endl;
			std::cout<<"x_1 = "<<calc_one_solution(a,b,c)<<std::endl;
		}
		if(solutions==2){
			std::cout<<"Two Solutions:"<<std::endl;
			std::cout<<"x_1 = "<<calc_two_solution_plus(a,b,c)<<std::endl;
			std::cout<<"x_2 = "<<calc_two_solution_minus(a,b,c)<<std::endl;
		}
	}
	catch(int param){
		if(param==0){
			std::cout<<"The expression is not a quadratic equation, closing program."<<std::endl;
		}
	}


	return 0;
}
int number_of_solutions(double a, double b, double c){
	//Diskriminante >0
	if  (((b*b)-(4*a*c))>0){
		return 2;
	}
	//Diskriminante =0
	if ((((b*b)-(4*a*c))==0)){
		return 1;
	}
	//Diskriminante <0
	if((((b*b)-(4*a*c))<0)){
		std::cout<<"No solution within the real numbers"<<std::endl;
		return 0;
	}
	return 0;
}
double calc_one_solution(double a,double b, double c){
	return ((-1)*b)/(2*a);
}
double calc_two_solution_plus(double a,double b, double c){
	return ((-1)*b+sqrt((b*b)-(4*a*c)))/(2*a);
}
double calc_two_solution_minus(double a,double b, double c){
	return ((-1)*b-sqrt((b*b)-(4*a*c)))/(2*a);
}
