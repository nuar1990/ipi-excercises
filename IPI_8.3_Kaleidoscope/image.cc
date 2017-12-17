/*
 * image.cc
 *
 *  Created on: Dec 14, 2017
 *      Author: nuar
 */

#include "image.h"
int main(){
	/* UNCOMMENT THE RESPECTIVE SECTIONS TO CHECK ASSIGNMENT */

	/*****************  b) *************************/
	Image image0=Image(4,3);
	std::cout<<to_string(image0)<<std::endl;

	/***************** c) +e)*************************/
	Image image1=chessboard(4,3,1);
	std::cout<<to_string(image1)<<std::endl;

	/***************** d) ****************/
	Image image2=chessboard(4,3,1);
	writePGM(image2,"board4x3.pgm");
	Image image3=readPGM("board4x3.pgm");
	if(image2==image3) std::cout<<"The images are the same."<<std::endl;
	else std::cout<<"The images are different"<<std::endl;

	/***************** e)+f) ******************/
	Image image4=chessboard(400,300,20);
	writePGM(image4,"board400x300.pgm");
	Image image5=readPGM("board400x300.pgm");
	if(image4==image5)std::cout<<"The images are the same."<<std::endl;
	else std::cout<<"The images are different"<<std::endl;

	/***************** g *******************/

	Image image6=chessboard(400,300,20);
	Image image7=invert_image(image6);
	writePGM(image7,"board400x300-inverse.pgm");

	/***************** h ******************/

	Image image8=readPGM("christmas.pgm");
	Image image9=invert_image(image8);
	writePGM(image9,"christmas-inverse.pgm");
}

/*
  * THIS IS THE ASSIGNMENT
  */

Image chessboard(unsigned int width, unsigned int height, unsigned int square_size){
	Image chess=Image(width,height);
	/* making square_size a divisor of width& height. This is a necessity to provide
	 * hardness for the function. If square_size has been changed
	 * the user will be informed */
	bool change=0;
	while(chess.width()%square_size!=0 || chess.height()%square_size!=0){
		square_size--;
		change=1;
	}
	if(change)std::cout<<"New Square_Size: "<<square_size<<std::endl;
	/* If lines of Image are even, color doesn't have to be changed on linebreak*/
	bool even=1;
	if((chess.width()/square_size)%2!=0) even=0;
	/* write chessPattern */
	bool color=0;
	int write;

	for(int y=0;y<chess.height();y+=square_size){
		for(int x=0;x<chess.width();x++){
			write=square_size;
			if(color){
				/*writing lines according to factor*/
				while(write>0){
					chess(x,(y+write-1))=255;
					write--;
				}
				/*change color */
				if((x+(y*chess.width())+1)%square_size==0)color=0;
			}
			else{
				/*writing next lines according to factor*/
				while(write>0){
					chess(x,(y+write-1))=0;
					write--;
				}
				/*change color */
				if((x+(y*chess.width())+1)%square_size==0)color=1;
			}
		}
		if(even) color=	(!color);
	}
	return chess;
}

Image invert_image(Image const& image){
	Image inverted_image=Image(image.width(),image.height());

	for(int y=0;y<inverted_image.height();y++){
		for(int x=0;x<inverted_image.width();x++){
			inverted_image(x,y)=255-image(x,y);
		}
	}
	return inverted_image;
}

/*
 * Here is the function that creates, chess patterns with just the image information,
 * and scales it properly. ----> NOT NECESSARY FOR THIS ASSIGNMENT.
 *
 *this function creates a chess pattern for any given Image, notice however that sensible results
 *are only given for even widths and heights.
 *This could be optimized for uneven edges, by setting factors to prime divisors -
 *but since its not necessary this isn't implemented.
 */
void createChessPattern(Image &img){

	/*Factors provide visibility for bigger images*/
	int fac=1; //std-setting
	if(img.width()%2 ==0){
		fac=std::ceil(img.width()/10);
		if(fac==0)fac=1;
		//making fac a divisor of width.
		while(img.width()%fac!=0){
			fac--;
		}
	}
	int vertFac=1;
	if(img.height()%2==0){
		vertFac=std::ceil(img.height()/10);
		if(fac==0)fac=1;
		while(img.height()%vertFac!=0){
			vertFac--;
		}
	}
	/* If lines of Image are even, color doesn't have to be changed on linebreak*/
	bool even=1;
	if((img.width()/fac )%2!=0) even=	0;

	/* write chessPattern */
	bool color=0;
	int write=fac;
	for(int y=0;y<img.height();y+=vertFac){
		for(int x=0;x<img.width();x++){
			if(color){
				/*writing lines according to factor*/
				write=vertFac;
				while(write>0){
					img(x,(y+write-1))=255;
					write--;
				}
				/*change color */
				if((x+(y*img.width())+1)%fac==0)color=0;
			}
			else{
				/*writing next lines according to factor*/
				write=vertFac;
				while(write>0){
					img(x,(y+write-1))=0;
					write--;
				}
				/*change color */
				if((x+(y*img.width())+1)%fac==0)color=1;
			}
		}
		if(even) color=	(!color);
	}
}
