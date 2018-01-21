/*
 * recursive_fcns.cc
 *
 *  Created on: Nov 26, 2017
 *      Author: nuar
 */
#include <iostream>

int sum(int N){
	if(N==0){
		return 0;
	}
	return sum(N-1)+N;
}
void convert_decimal(int value, int base){
	if(base>10){
		throw std::invalid_argument("function not implemented for bases >10");
	}
    if(value == 0 || base==10){
        std::cout<<value;
    }
    else{
    	convert_decimal(value/base,base);
    	std::cout<<value%base;
    }
}
int square(int number){
	return number*number;
}

int power(int base,int n){
	if(n==1){
		return base;
	}
	if(n%2==0){
		return power(base,n/2)*power(base,n/2);
		//return square(power(base,n/2));
	}
	if(n%2!=0){
		return base*power(base,n-1);
	}
}


int main(){
	std::cout<<"n=12 sum=(n(n+1))/2) solved recursively is: ";
	std::cout<<sum(12)<<std::endl;
	std::cout<<"1278_10 to _2: ";
	convert_decimal(1278,2);
	std::cout<<std::endl;

	std::cout<<"1278_10 to _8: ";
	convert_decimal(1278,8);
	std::cout<<std::endl;

	std::cout<<"12^3: "<<power(12,8)<<std::endl;
	return 0;
}



