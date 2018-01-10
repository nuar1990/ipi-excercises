/*
 * tree.cc
 *
 *  Created on: Jan 9, 2018
 *      Author: nuar
 */

#include "tree.h"

Tree::Tree() {
	stumpBase	='_';
	branch1  	='/';
	branch2 	='\\';
	deco1		='@';
	deco2		='0';
}

Tree::~Tree() {}

//Scalable Tree, with randomized decoration
//Using Color Wrapper
void Tree::draw(int scale){
	StringMan color=StringMan();
	int size=3*scale;
	drawCrown(size);
	bool sw=false;
	//iterates over the size of the tree
	for(int i=0;i<size-1;i++){
		//determine where to start drawing
		for (int j=0;j<size-1-i;j++){
			std::cout<<" ";
		}
		color.writeGreen(branch1);
		bool s=false;
		//interior of the tree
		for(int j=0;j<(2*i)+1;j++){
			if(s&&!sw) 	color.writeGreen(branch1);
			if(s&&sw) 	color.writeGreen(branch2);
			if(!s){
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(1, 8);
				int rand=dis(gen);
				if(rand<5) color.writeGreen(stumpBase);
				if(rand==5) color.writeBlue(deco1);
				if(rand==6) color.writeRed(deco2);
				if(rand==7) color.writeBlue(deco1);
				if(rand==8) color.writeRed(deco2);
			}
			s=!s;
		}
		sw=!sw;
		color.writeGreen(branch2);
		std::cout<<std::endl;
	}
	drawStomp(size);
}
/*
 * Static function placing crown in the middle of the output
 */
void Tree::drawCrown(int size){
	StringMan color=StringMan();
	for (int i=0;i<size-1;i++){
		std::cout<<" "<<std::flush;
	}
	std::string print="\\ /";
	color.writeYellow(print);
	std::cout<<std::endl;
	for (int i=0;i<size-3;i++){
		std::cout<<" ";
	}
	print="-->*<--";
	color.writeYellow(print);
	std::cout<<std::endl;
}

/*
 * Static function placing stomp in the middle of the tree;
 */
void Tree::drawStomp(int size){
	StringMan color=StringMan();
	for(int i=0;i<size-2;i++){
		std::cout<<" ";
	}
	std::string print="[___]";
	color.writeYellow(print);
}
