/*
 * pali.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: nuar
 */

#include "pali.h"

std::string reverse_string(std::string s){
	std::reverse(s.begin(),s.end());
	return s;
}

bool isPalindrom(std::string& s){
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	if(s.size()<3) return false;
	std::string reverse= reverse_string(s);
	if(s.compare(reverse)!=0) return false;
	return true;
}
