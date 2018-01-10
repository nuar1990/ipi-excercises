/*
 * tree.h
 *
 *  Created on: Jan 9, 2018
 *      Author: nuar
 */

#ifndef TREE_H_
#define TREE_H_
#include "stringMan.h"
#include <random>
class Tree {
private:
	std::string stumpBase,deco1,deco2,branch1,branch2;
public:
	Tree();
	void draw(int scale);
	void drawCrown(int size);
	void drawStomp(int size);
	virtual ~Tree();
};

#endif /* TREE_H_ */
