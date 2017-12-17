/*
 * kaleidoscope.cc
 *
 *  Created on: Dec 14, 2017
 *      Author: nuar
 */

#include "image.h"
#include <cmath>
#include <vector>

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
	Image mirror_image= Image();
	if(image.width()<image.height()) mirror_image=Image(image.height(),image.height());
	else mirror_image=Image(image.width(),image.width());

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
	writePGM(image9,"my_image.pgm");
}


