/*
 * stringMan.cc
 *
 *  Created on: Jan 9, 2018
 *      Author: nuar
 */

#include "stringMan.h"

StringMan::StringMan() {}

StringMan::~StringMan() {}

void StringMan::writeBlue(std::string& text){
	std::cout<<"\033[1;34m"<<text<<"\033[m";
}
void StringMan::writeRed(std::string& text){
	std::cout<<"\033[1;31m"<<text<<"\033[m";
}
void StringMan::writeYellow(std::string& text){
	std::cout<<"\033[1;33m"<<text<<"\033[m";
}
void StringMan::writeGreen(std::string& text){
	std::cout<<"\033[1;32m"<<text<<"\033[m";
}


