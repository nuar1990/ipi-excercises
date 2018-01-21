/*
 * insertion_sort.cc
 *
 *  Created on: Jan 21, 2018
 *      Author: nuar
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template<typename T>
void insertion_sort(std::vector<T>& vec);

int main(){
	std::vector<double> one={12.,-5.,0.,-1.,20.,9.};
	std::vector<std::string> two={"h","a","1","1","o"};
	std::vector<int> three={2,5,4,-7,12,1};
	std::vector<bool> four={false,true,false};
	std::vector<char> five={'h','a','l','l','o'};

	std::vector<double>::iterator it=one.begin();
	std::vector<double>::iterator it2=one.end();

	insertion_sort(one);
	insertion_sort(two);
	insertion_sort(three);
	insertion_sort(four);
	insertion_sort(five);
}




template<typename T>
void insertion_sort(std::vector<T>& vec){
    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::rotate(std::upper_bound(vec.begin(), it, *it), it, std::next(it));
    for(auto it=vec.begin();it!=vec.end();++it)
    	std::cout<<*it<<" ";
	std::cout<<"\n";
}
