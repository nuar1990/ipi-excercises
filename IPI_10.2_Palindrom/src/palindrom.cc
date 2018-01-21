/*
 * palindrom.cc
 *
 *  Created on: Jan 15, 2018
 *      Author: nuar
 */


#include <iostream>
#include <string>
#include <fstream>
#include "simpletests.h"
#include "pali.h"


int main(){
        std::cout<<"Checking all lines of words.txt whether they are palindroms: "<<std::endl;
	std::string item_name;
	std::ifstream nameFileout;
	nameFileout.open("words.txt");
	std::string line;
	while(std::getline(nameFileout, line))
	{
		//test(isPalindrom(line));
		//comment out the lines below if you need less information in terminal
		//instead use simpletests test above
		//or use test_eq with isPalindrom(line) <bool> since its a template function.
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		test_eq(line,reverse_string(line));
	}
	simpletests::test_result();
	return 0;
}


