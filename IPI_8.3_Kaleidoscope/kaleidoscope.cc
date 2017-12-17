/*
 * kaleidoscope.cc
 *
 *  Created on: Dec 14, 2017
 *      Author: nuar
 */

#include "image.h"
#include <cmath>
#include <vector>

Image stretch_to_quadratic(Image const& image){
	Image stretched;
	std::cout<<image.height()<<" "<<image.width()<<std::endl;
	if(image.height()==image.width()){
		return image;
	}
	if(image.width()<image.height()) stretched=Image(image.height(),image.height());
	if(image.height()<image.width()) stretched=Image(image.width(),image.width());

	/* bounds */
	int x_boundaryL=floor((stretched.width()-image.width())/2);
	int x_boundaryR=stretched.width()-x_boundaryL;
	int y_boundaryB=floor((stretched.height()-image.height())/2);
	int y_boundaryT=stretched.height()-y_boundaryB;

	std::cout<<x_boundaryL<<" "<<x_boundaryR<<std::endl;
	std::cout<<y_boundaryB<<" "<<y_boundaryT<<std::endl;
	std::cout<<"--------------"<<std::endl;
	for(int y=0;y<stretched.height();y++){
		for(int x=0;x<stretched.width();x++){
			if(x<=x_boundaryL) stretched(x,y)=0;
			if(x>x_boundaryR) stretched(x,y)=0;
			if(y<=y_boundaryB) stretched(x,y)=0;
			if(y>y_boundaryT) stretched(x,y)=0;
			else stretched(x,y)=image(x-x_boundaryL,y-y_boundaryB);
		}
	}
	for(int y=0;y<stretched.height();y++){
		for(int x=0;x<stretched.width();x++){
			int num=stretched(x,y);
			if(num >255) stretched(x,y)=0;
		}
	}

	return stretched;
}

Image mirror_x(Image const& image){
	Image mirror_image=Image(image.width()*2,image.height());
	for(int y=0;y<mirror_image.height();y++){
		for(int x=0;x<mirror_image.width();x++){
			if(x<image.width()){
				mirror_image(x,y)=image(x,y);
			}
			else {
				mirror_image(x,y)=image((2*image.width())-x-1,y);
			}
		}
	}
	return mirror_image;
}

Image mirror_y(Image const& image){
	Image mirror_image= Image(image.width(),image.height()*2);
	for(int y=0;y<mirror_image.height();y++){
		for(int x=0;x<mirror_image.width();x++){
			if(y<image.height()){
				mirror_image(x,y)=image(x,y);
			}
			else {
				mirror_image(x,y)=image(x,(2*image.height())-y-1);
			}
		}
	}
	return mirror_image;
}
Image kaleidoscope4(Image const& image){
	Image kaleidoscope1=mirror_x(image);
	Image kaleidoscope4=mirror_y(kaleidoscope1);

	return kaleidoscope4;
}
Image kaleidoscope8(Image const& image){
	//Image image0= stretch_to_quadratic(image);
	Image mirror_image=Image(image.width(),image.height());

	double diagonal_slope=0- ((double)mirror_image.height()/mirror_image.width());

	for(int y=0;y<mirror_image.height();y++){
		for(int x=0;x<mirror_image.width();x++){
			double threshold=(x+1)*diagonal_slope*(-1);
			double c=threshold-y;
			if(c>0) mirror_image(x,y)=image(y,x);
			else mirror_image(x,y)=image(x,y);
		}
	}
	return kaleidoscope4(mirror_image);
}

int main(){
	Image image0=readPGM("christmas.pgm");
	Image image1=mirror_x(image0);
	Image image2=mirror_y(image0);
	Image image3=kaleidoscope4(image0);
	Image image4=kaleidoscope8(image0);
	writePGM(image1,"christmas-mirror-x.pgm");
	writePGM(image2,"christmas-mirror-y.pgm");
	writePGM(image3,"christmas-kaleidoscope-4.pgm");
	writePGM(image4,"christmas-kaleidoscope-8.pgm");

	Image image5=readPGM("my_image.pgm");
	Image image6=mirror_x(image5);
	Image image7=mirror_y(image5);
	Image image8=kaleidoscope4(image5);
	Image image9=kaleidoscope8(image5);
	writePGM(image9,"my_image_kaleidoscope.pgm");
}


