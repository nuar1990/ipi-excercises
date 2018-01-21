/*
 * array_sort.cc
 *
 *  Created on: Nov 16, 2017
 *      Author: nuar
 */


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
/*
 * array requires c++11 compiler
 */
std::array<int,10> bubbleSort(std::array<int,10> arrayToSort){
	unsigned int n=arrayToSort.size();
	unsigned int newn;
	unsigned int temp;
	do{
		newn=1;
		for(unsigned int i=0;i<n-1;++i){
			if(arrayToSort[i]>arrayToSort[i+1]){
				temp=arrayToSort[i];
				arrayToSort[i]=arrayToSort[i+1];
				arrayToSort[i+1]=temp;
				newn=i+1;
			}
		}
		n=newn;
	}while(n>1);
	return arrayToSort;
}
int main(int argc, char *argv[]){
	std::array<int,10> arrayToSort{{12,6,10,2,1,22,4,16,12,7}};
	std::cout<<"Before:"<<std::endl;
	for(unsigned int i=0;i<arrayToSort.size();i++){
		std::cout<<std::setw(20)<<"entry "<<i+1<<" :"<<arrayToSort[i]<<std::endl;
	}
	//std::sort(arrayToSort.begin(),arrayToSort.end());
	//well that was lame but time efficient, here's a variation for a bubble sort
	//which is everything but time efficient-(I'm asssuming we shouldn't be using the algorithm lib)
	arrayToSort=bubbleSort(arrayToSort);
	std::cout<<"After:"<<std::endl;
	for(unsigned int i=0;i<arrayToSort.size();i++){
		std::cout<<std::setw(20)<<"entry "<<i+1<<" :"<<arrayToSort[i]<<std::endl;
	}
}


