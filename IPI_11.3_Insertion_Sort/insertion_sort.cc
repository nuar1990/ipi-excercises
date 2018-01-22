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


/*	This function can handle any Container that specified an Iterator:
*	vectors, lists incl./
*	Here is how the implemented algorithms work:
*	std::rotate rotates the order of elements so that the middle element
*	becomes the new first element.
*	Therefore 3 Arguments:
*
*	(first,last): Forward Iterator - initial and final pos of the sequence to be rotated
*	--> Using std::upper_bound , which returns an iterator to the greatest element in the range
*		--> 	If there is no greatest element, or equivalent greatest elements
*				-> returning the pos of the last element--> Which is exactly
*	   		 	the functionality we try to accomplish in insertion_sorts for the first element.
*	--> range always incremented by one for each iteration, only looking at a position once.
*	    --> this is what we aim to do with insertion_sort.
*		--> std::next(it) provides an Iterator-Element that will be determine the iterator to the last element of
*		    the range that needs to be viewed.
*		--> To its currently correct position.
*	--> Ultimately we get the range that comes before the current element.
*
*
*	(middle): Forward Iterator pointing to the element within the range(first,last)
*	--> In this case the currently viewed element.
*
*   i.e. in pseudo code:
*
*   given is a vector<int> vec={5,3,9,7}
*
*   first step:
*   std::rotate(std::upper_bound(vec.begin(),pos(0),5),pos(0), std::next(pos0))
*   --> (5,3,9,7)
*   second step:
*   std::rotate(std::upper_bound(vec.begin(),pos(1),3),pos(1), std::next(pos1))
*   --> //range to view 5,3 --> 5 greatest element so we take the iter_pos of 5
*   	as the beginning and the end of the range is pos(1)=3
*  	--> then we copy the pos(1) before that range.
*   --> (3,5,9,7)
*
*   and so on...
*/

template<typename T>
void insertion_sort(T& data){
	for(auto it = data.begin(); it != data.end(); ++it)
        std::rotate(std::upper_bound(data.begin(), it, *it), it, std::next(it));
    for(auto it= data.begin();it != data.end(); ++it)
    	std::cout<<*it<<" ";

	std::cout<<"\n";
}

