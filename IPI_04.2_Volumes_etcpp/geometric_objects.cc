/*
 * geometric_objects.cc
 *
 *  Created on: Nov 17, 2017
 *      Author: nuar
 */
#include <iostream>
#include "Rechteck.h"
#include "Quadrat.h"
#include "Kreis.h"
#include "Quader.h"
#include "Wuerfel.h"
#include "Kugel.h"

int main(int argc, char *argv[]){
	unsigned int dimension;
	unsigned int selector;
	double a,b,c,r;
	while(1){
		try{
			std::cout<<std::endl;
			std::cout<<"Geben Sie die Dimension ein: ";
			std::cin>>dimension;
			if(std::cin.fail()){
				throw(4);
			}
			if(dimension!=2&&dimension!=3){
				throw(0);
			}
			std::cout<<"Welches Objekt wollen Sie betrachten?"<<std::endl;
			if(dimension==2){
				std::cout<<"0 - Rechteck"<<std::endl;
				std::cout<<"1 - Quadrat"<<std::endl;
				std::cout<<"2 - Kreis"<<std::endl;
				std::cin>>selector;

				if(std::cin.fail()){
					throw(4);
				}
				if(selector!=0 && selector!=1 && selector!=2){
					throw(1);
				}

				if(selector==0){
					std::cout<<"Geben Sie die Seitenlaengen des Rechtecks ein:"<<std::endl;
					std::cin>>a;
					std::cin>>b;
					if(std::cin.fail()){
						throw(4);
					}
					if(a<0||b<0){
						throw(3);
					}
					Rechteck myRechteck= Rechteck(a,b);
					std::cout<<"Das Rechteck hat einen Umfang von "<<myRechteck.circumference_rectangle()
							 <<" und eine Flaeche von "<<myRechteck.area_rectangle()<<std::endl;
				}

				if(selector==1){
					std::cout<<"Geben Sie die Seitenlaenge des Quadrats ein:"<<std::endl;
					std::cin>>a;
					if(std::cin.fail()){
						throw(4);
					}
					if(a<0){
						throw(3);
					}
					Quadrat myQuadrat= Quadrat(a);
					std::cout<<"Das Quadrat hat einen Umfang von "<<myQuadrat.circumference_square()
							 <<" und eine Flaeche von "<<myQuadrat.area_square()<<std::endl;
				}

				if(selector==2){
					std::cout<<"Geben Sie den Radius des Kreises ein:"<<std::endl;
					std::cin>>r;
					if(std::cin.fail()){
						throw(4);
					}
					if(r<0){
						throw(3);
					}
					Kreis myKreis= Kreis(r);
					std::cout<<"Der Kreis hat einen Umfang von "<<myKreis.circumference_circle()
							 <<" und eine Flaeche von "<<myKreis.area_circle()<<std::endl;
				}
			}
			if(dimension==3){
				std::cout<<"0 - Quader"<<std::endl;
				std::cout<<"1 - Wuerfel"<<std::endl;
				std::cout<<"2 - Kugel"<<std::endl;
				std::cin>>selector;

				if(std::cin.fail()){
					throw(4);
				}
				if(selector!=0 && selector!=1 && selector!=2){
					throw(1);
				}

				if(selector==0){
					std::cout<<"Geben Sie die Seitenlaengen des Quaders ein:"<<std::endl;
					std::cin>>a;
					std::cin>>b;
					std::cin>>c;
					if(std::cin.fail()){
						throw(4);
					}
					if(a<0||b<0||c<0){
						throw(3);
					}
					Quader myQuader= Quader(a,b,c);
					std::cout<<"Das Rechteck hat einen Oberflaecheninhalt von "<<myQuader.surface_area_cuboid()
							 <<" und ein Volumen von "<<myQuader.volume_cuboid()<<std::endl;
				}

				if(selector==1){
					std::cout<<"Geben Sie die Seitenlaenge des Wuerfels ein:"<<std::endl;
					std::cin>>a;
					if(std::cin.fail()){
						throw(4);
					}
					if(a<0){
						throw(3);
					}
					Wuerfel myWuerfel= Wuerfel(a);
					std::cout<<"Der Wuerfel hat einen Oberflaecheninhalt von "<<myWuerfel.surface_area_cube()
							 <<" und ein Volumen von "<<myWuerfel.volume_cube()<<std::endl;
				}

				if(selector==2){
					std::cout<<"Geben Sie den Radius der Kugel ein:"<<std::endl;
					std::cin>>r;
					if(std::cin.fail()){
						throw(4);
					}
					if(r<0){
						throw(3);
					}
					Kugel myKugel= Kugel(r);
					std::cout<<"Der Kreis hat einen Oberflaecheninhalt von "<<myKugel.surface_area_sphere()
							 <<" und ein Volumen von "<<myKugel.volume_sphere()<<std::endl;
				}

			}
		}
		catch(int param){
			if(param==0){
				std::cout<<"Fehler:- Korrekte Dimensionen sind '2' und '3'."<<std::endl;
			}
			if(param==1){
				std::cout<<"Fehler:- Korrekte Eingaben sind '0','1' und '2'"<<std::endl;
			}
			if(param==3){
				std::cout<<"Das Objekt kann keine negative Laengen besitzen"<<std::endl;
			}
			if(param==4){
				std::cout<<"Invalid Argument - Closing Program."<<std::endl;
				break;
			}
		}
	}
	return 0;
}
