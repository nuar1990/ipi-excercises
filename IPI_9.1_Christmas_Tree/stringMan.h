/*
 * stringMan.h
 *
 *  Created on: Jan 9, 2018
 *      Author: nuar
 */

#ifndef STRINGMAN_H_
#define STRINGMAN_H_
#include <string>
#include <iostream>
#include <iomanip>

class StringMan {
public:
	StringMan();
	virtual ~StringMan();

	/*Wrapper Functions for strings to produce colored output*/
	void writeRed(std::string& text);
	void writeBlue(std::string& text);
	void writeGreen(std::string& text);
	void writeYellow(std::string& text);
};

#endif /* STRINGMAN_H_ */
