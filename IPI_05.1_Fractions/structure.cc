/*
 * structure.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: nuar
 */
#include <iostream>
#include <cmath>

struct Fraction{
	int numerator;
	int denominator;
};

void reduce(Fraction &n){
	int a=abs(n.numerator);
	int b=abs(n.denominator);
	if(b==0){
		throw std::invalid_argument("Keep it real.");
	}
	int ggt;

	while(1){
		if(a==0){
			ggt=b;
			break;
		}
		else if(b==0){
			ggt=a;
			break;
		}
		else if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	n.numerator = n.numerator/ggt;
	n.denominator =n.denominator/ggt;
}
Fraction sum(Fraction &a,Fraction &b){
	Fraction sum={
			(a.numerator * b.denominator)+(b.numerator * a.denominator),
			(a.denominator *b.denominator)
	};
	reduce(sum);
	return sum;
}
Fraction mult(Fraction &a,Fraction &b){
	Fraction mult={
			(a.numerator * b.numerator),
			(a.denominator *b.denominator)
	};
	reduce(mult);
	return mult;
}
Fraction reciprocal(Fraction &a){
	Fraction reci={
			a.denominator,
			a.numerator
	};
	return reci;
}
double decimal(Fraction &a){
	return (double) a.numerator / a.denominator;
}
int main(){
	Fraction first={12,53};
	Fraction second ={3,4};
	Fraction third = {-1,2};
	Fraction fourth= {1,5};

	Fraction one= mult(second,third);
	Fraction two= sum(first, one);
	Fraction three= reciprocal(fourth);
	Fraction four= mult(two,three);
	std::cout<<"Fraction: ("<<four.numerator<<") ("<<four.denominator<<")"<<std::endl;
	std::cout<<"Decimal: "<<decimal(four);
}
