/*
 * insertion_sort.cc
 *
 *  Created on: Jan 21, 2018
 *      Author: nuar
 */
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>

template<typename T>
void insertion_sort(T& data);

int main(){
	std::vector<double> one={12.,-5.,0.,-1.,20.,9.};
	std::vector<std::string> two={"h","a","1","1","o"};
	std::vector<int> three={2,5,4,-7,12,1};
	std::vector<bool> four={false,true,false};
	std::vector<char> five={'h','a','l','l','o'};
	std::list<double> myList={12.,-5., 8., 0., -1., 20., 9.};


	insertion_sort(one);
	insertion_sort(two);
	insertion_sort(three);
	insertion_sort(four);
	insertion_sort(five);
	insertion_sort(myList);
}


//This function can handle any Container that specified an Iterator
//vectors, lists incl.
template<typename T>
void insertion_sort(T& data)
{
	for (auto it = data.begin(); it != data.end(); ++it)
        std::rotate(std::upper_bound(data.begin(), it, *it), it, std::next(it));
    for(auto it=data.begin();it!=data.end();++it)
    	std::cout<<*it<<" ";
	std::cout<<"\n";
}

