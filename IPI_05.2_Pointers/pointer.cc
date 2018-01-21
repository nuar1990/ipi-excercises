/*
 * pointer.cc
 *
 *  Created on: Nov 26, 2017
 *      Author: nuar
 */
#include <iostream>
void swap1(double a, double b){
	std::cout<<"Initial:"<<std::endl;
	std::cout<<"a: "<<a<<" b: "<<b<<std::endl;
	double temp;
	temp=a;
	a=b;
	b=temp;
	std::cout<<"After swap1:"<<std::endl;
	std::cout<<"a: "<<a<<" b: "<<b<<std::endl;
}
void swap2(double &a, double &b){
	std::cout<<"Initial:"<<std::endl;
	std::cout<<"a: "<<a<<" b: "<<b<<std::endl;
	double temp=a;
	a=b;
	b=temp;
	std::cout<<"After swap2:"<<std::endl;
	std::cout<<"a: "<<a<<" b: "<<b<<std::endl;

}
void swap3(double *a, double *b){
	std::cout<<"Initial:"<<std::endl;
	std::cout<<"a: "<<*a<<" b: "<<*b<<std::endl;
	double temp=*a;
	*a= *b;
	*b=temp;
	//*dereferencing adress via *
	std::cout<<"After swap3:"<<std::endl;
	std::cout<<"a: "<<*a<<" b: "<<*b<<std::endl;
}
double *maximum_value(double *a,int size){
	double *value=&a[0];
	for(int i=0;i<size;i++){
		std::cout<<a[i]<<" at "<<&a[i]<<std::endl;
		if(a[i]>=*value){
			value=&a[i];
		}
	}
	return value;
}
int length_string(const char *str){
	int count=0;
	while(str[count]!=0){
		count++;
	}
	return count;
}

void reverse_string(char *str){
	int length= length_string(str)-1;
	int i=0;
	char temp;

	while(length>=i){

		temp =str[length];
		str[length]=str[i];
		str[i]=temp;
		length--;
		i++;
	}
	std::cout<<"The reversed string of my name is: "<<str<<std::endl;
}
int main(){
	double a=7,b=12;
	swap1(a,b);
	swap2(a,b);
	swap3(&a,&b);
	double c[5]={1.,4.,12.,3.,5.};
	double &largest=*maximum_value(c,5);
	std::cout<<"largest element: "<<largest<<" at: "<<&largest<<std::endl;
	char name[]={"Frank Streicher"};
	int size=length_string(name);
	std::cout<<"The string with my name ("<<name<<") contains "<<size<<" characters."<<std::endl;
	reverse_string(name);
}




