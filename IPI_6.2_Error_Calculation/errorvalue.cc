/*
 * errorvalue.cc
 *
 *  Created on: Dec 2, 2017
 *      Author: nuar
 */

#include "errorvalue.h"
#include <iostream>
#include <math.h>
ErrorValue::ErrorValue():w(0),abs_error(0){}
ErrorValue::ErrorValue(double w, double abs_error){
	this->w=w;
	this->abs_error=abs_error;
}
void ErrorValue::setW(double w){
	this->w=w;
}
void ErrorValue::set_abs_error(double abs_error){
	this->abs_error=abs_error;
}
double ErrorValue::value()const{
	return this->w;
}
double ErrorValue::absolute()const{
	return this->abs_error;
}
double ErrorValue::relative(){
	return this->absolute()/this->value();
}
ErrorValue ErrorValue::operator +(const ErrorValue& b){
	ErrorValue s=ErrorValue(this->w,this->abs_error);
	s.setW(s.value()+b.value());
	s.set_abs_error(sqrt(pow(s.absolute(),2)+pow(b.absolute(),2)));
	return s;
}
ErrorValue ErrorValue::fromMeasurements(double* values,int N){
	double average=0;
	double sum_abs_error=0;
	for(int i=0;i<N;i++){
		average+=values[i];
	}
	average=average/N;
	for(int i=0;i<N;i++){
		sum_abs_error+=pow(values[i]-average,2);
	}
	sum_abs_error=sqrt(sum_abs_error/(N-1));
	ErrorValue list=ErrorValue(average,sum_abs_error);
	return list;
}
ErrorValue::~ErrorValue() {}

