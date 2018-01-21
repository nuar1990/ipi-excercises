/*
 * main.cc
 *
 *  Created on: Jan 19, 2018
 *      Author: nuar
 */
#include "myList.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <vector>
#include <list>

int main(){
	int N=1000;
	MyList my_list=MyList();

	for(int i=0;i<N;++i){
		my_list.push_back(i+1);
	}

	if(my_list.isEmpty()){
		std::cerr<<"Die Liste ist leer!"<<std::endl;
	}

	unsigned int count=0;
	for(MyList::Iterator it=my_list.first();it!=my_list.last();++it){
		std::cout<<std::setw(floor(log10(N))+1)<<it.printValue()<<"  "; //dyn length according to N
		count++;
		if(count%20==0) std::cout<<std::endl; //prevents artifacts from terminal(max length display)

	}
	std::cout<<"\n";
	my_list.remove();

	//b)
	double tstart,tstop,time;
	std::vector<double> my_list_time, my_list_stl_time;

	for(N=20000;N<=100000;N+=20000){
		tstart=clock();

		MyList list=MyList();
		for(int i=0;i<N;i++){
			list.push_back(i+1);
		}
		tstop=clock();
		time=tstop-tstart;
		my_list_time.push_back(time);

		tstart=clock();


		std::list<int> stlList;
		for(int i=0;i<N;i++){
			stlList.push_back(i+1);
		}
		tstop=clock();
		time=tstop-tstart;
		my_list_stl_time.push_back(time);
	}

	for(unsigned int i=0; i<my_list_time.size();++i){
		std::cout<<my_list_time[i]<<"  "<<my_list_stl_time[i]<<std::endl;
	}

	return 0;
	//My implementation adds elements in ~O(n) time
	//-->Same complexity as STL-Lib, but it adds elements in roughly half the time.
	// That the time for the STL-lib implementation is higher isn't surprising:
	// It needs to add proper encapsulation for other functionalities.
	// +it's created by using inline templates (static polymorphism)
	// that doesn't really have an influence on the runtime however.

}
