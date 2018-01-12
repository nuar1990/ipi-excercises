/*
 * gifts.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: nuar
 */
#include "rectangle.h"
#include <vector>
#include <algorithm>
#include <climits>
#include "canvas.hh"

//global variables from gifts.txt
Rectangle              table(Point(100.0, 80.0));
Rectangle              tree_stand(Point(30.0, 30.0));

std::vector<Rectangle> gifts = { Rectangle(Point(20.0, 10.0)),
                                 Rectangle(Point(10.0, 11.0)),
                                 Rectangle(Point(3.0, 46.0)),
                                 Rectangle(Point(3.0, 4.0)),
                                 Rectangle(Point(6.0, 16.0)),
                                 Rectangle(Point(10.0, 20.0)),
                                 Rectangle(Point(20.0, 8.0)),
                                 Rectangle(Point(12.0, 37.0)),
                                 Rectangle(Point(11.0, 15.0)),
                                 Rectangle(Point(40.0, 63.0)),
                                 Rectangle(Point(23.0, 6.0)),
                                 Rectangle(Point(16.0, 12.0)),
                                 Rectangle(Point(25.0, 20.0)),
                                 Rectangle(Point(67.0, 3.0)),
                                 Rectangle(Point(31.0, 29.0)),
                                 Rectangle(Point(12.0, 11.0)),
                                 Rectangle(Point(8.0, 9.0)),
                                 Rectangle(Point(3.0, 8.0)),
                                 Rectangle(Point(21.0, 13.0)),
                                 Rectangle(Point(46.0, 13.0)),
                                 Rectangle(Point(11.0, 75.0)),
                                 Rectangle(Point(4.0, 3.0)),
                                 Rectangle(Point(19.0, 7.0)),
                                 Rectangle(Point(33.0, 7.0)),
                                 Rectangle(Point(6.0, 16.0)),
                                 Rectangle(Point(21.0, 4.0)),
                                 Rectangle(Point(8.0, 8.0)),
                                 Rectangle(Point(3.0, 86.0)),
                                 Rectangle(Point(20.0, 6.0)),
                                 Rectangle(Point(21.0, 3.0)),
                                 Rectangle(Point(13.0, 59.0)),
                                 Rectangle(Point(4.0, 20.0))
};

//(b)
double bssf_score(Rectangle const& free, Rectangle const& obj){
	double big_number= 1e300;
	if((free.width()-obj.width()>=0) && (free.height()-obj.height()>=0))
		return std::min(free.width()-obj.width(),free.height()-obj.height());
	else return big_number;
}
//(e)
std::vector<Rectangle> sas_rule(Rectangle const& free, Rectangle const& best){
	std::vector<Rectangle> sas;
	if(free.width()<free.height()){
			Point p0=Point(free.getX0(),best.getY1());
			//care: x0 in free rectangle isnt always zero, new point must be stored relative
			//to where the free rectangle is located on the table.
			Point p1=Point(free.getX0()+best.getX1(),free.getY1());
			Rectangle left=Rectangle(p0,p1);
			p0=Point(free.getX0()+best.getX1(),free.getY0());
			Rectangle right=Rectangle(p0,free.getP1());
			sas.push_back(left);
			sas.push_back(right);
	}
	else{
		Point p0=Point(free.getX0(),free.getY0()+best.getY1());
		Rectangle top=Rectangle(p0,free.getP1());
		p0=Point(free.getX0()+best.getX1(),free.getY0());
		Point p1=Point(free.getX1(),free.getY0()+best.getY1());
		p0=Point(free.getX0()+best.getX1(),free.getY0());
		Rectangle bottom=Rectangle(p0,p1);
		sas.push_back(top);
		sas.push_back(bottom);
	}
	return sas;
}



int main(){
	//initialized with all gifts=copy of gifts variable + pushed tree-stand
	std::vector<Rectangle> to_be_placed=gifts;
	to_be_placed.push_back(tree_stand);
	//no intializiation necessary, will be filled during placement
	std::vector<Rectangle> already_placed;
	//intialized with the size of the table
	std::vector<Rectangle> free_rectangles;
	free_rectangles.push_back(table);
	for(int i=0;i<to_be_placed.size();i++){
		std::cout<<to_string(to_be_placed[i])<<std::endl;
	}

	while(true){
		//variables to determine optimal index
		double min=INT_MAX;
		unsigned int best_free,best_obj;
		//(c)
		for(unsigned int i=0;i<to_be_placed.size();i++){
			for(unsigned int j=0;j<free_rectangles.size();j++){
				if(min>bssf_score(free_rectangles[j],to_be_placed[i])){
					min=bssf_score(free_rectangles[j],to_be_placed[i]);
					best_free=j;
					best_obj=i;
				}
			}
		}

		//(d)
		//variable to check whether obj will be added as transposed
		bool transpose=false;
		for(unsigned int i=0;i<to_be_placed.size();i++){
			for(unsigned int j=0;j<free_rectangles.size();j++){
				if(min>bssf_score(free_rectangles[j].transpose(),to_be_placed[i].transpose())){
					min=bssf_score(free_rectangles[j].transpose(),to_be_placed[i].transpose());
					best_free=j;
					best_obj=i;
					transpose=true;
				}
			}
		}
		std::cout<<"Index of free space + Index of object to place: "<<best_free<<"("<<to_string(free_rectangles[best_free])<<") "<<best_obj<<"("<<to_string(to_be_placed[best_obj])<<")"<<" min:"<<min<<std::endl;

		//(e)
		if(min>=1000000) {
			std::cout<<"There is no more space, for another gift."<<std::endl;
			break;
		}
		else{
			std::vector<Rectangle> newRectangles;
			if(transpose){
				to_be_placed[best_obj].transpose().translate(free_rectangles[best_free].getP0());

				already_placed.push_back(to_be_placed[best_obj].transpose());
				newRectangles=sas_rule(free_rectangles[best_free].transpose(),to_be_placed[best_obj].transpose());
			}
			else{
				to_be_placed[best_obj].translate(free_rectangles[best_free].getP0());
				already_placed.push_back(to_be_placed[best_obj]);
				newRectangles=sas_rule(free_rectangles[best_free],to_be_placed[best_obj]);
			}

			to_be_placed.erase(to_be_placed.begin()+best_obj);
			free_rectangles.erase(free_rectangles.begin()+best_free);
			free_rectangles.insert(std::end(free_rectangles),std::begin(newRectangles),std::end(newRectangles));
		}
		//(f)
		for(int i=0;i<free_rectangles.size();i++){
			for(int j=0;j<free_rectangles.size();j++){
				if(j>i){
					Rectangle uni=rectangle_union(free_rectangles[i],free_rectangles[j]);
					if(		free_rectangles[i].getX0()>=uni.getX0() &&
							free_rectangles[i].getX1()<=uni.getX1() &&
							free_rectangles[i].getY0()>=uni.getY0() &&
							free_rectangles[i].getY1()<=uni.getY1() &&
							free_rectangles[j].getX0()>=uni.getX0() &&
							free_rectangles[j].getX1()<=uni.getX1() &&
							free_rectangles[j].getY0()>=uni.getY0() &&
							free_rectangles[j].getY1()<=uni.getY1() )
						free_rectangles.erase(free_rectangles.begin()+i);
						free_rectangles.erase(free_rectangles.begin()+j);
						free_rectangles.push_back(uni);
				}
			}
		}
	}
	std::cout<<"Gifts placed: "<<std::endl;
	for(int i=0;i<already_placed.size();i++){
		std::cout<<to_string(already_placed[i])<<std::endl;
	}


	return 0;
}

