/*
 * myvector.cc
 *
 *  Created on: Dec 1, 2017
 *      Author: nuar
 */
#include <iostream>
#include <math.h>
#include "myvector.h"

#define PI 3.14159265

MyVector::MyVector():x(0),y(0),z(0){}
MyVector::MyVector(float x, float y, float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
void MyVector::print(){
	std::cout<<"x: "<<this->getX()<<" y: "<<this->getY()<<" z: "<<this->getZ()<<std::endl;
}
void MyVector::setX(float x){
	this->x=x;
}
void MyVector::setY(float y){
	this->y=y;
}
void MyVector::setZ(float z){
	this->z=z;
}
void MyVector::setValues(float newX,float newY, float newZ){
	this->x=newX;
	this->y=newY;
	this->z=newZ;
}
float MyVector::getX()const{
	return this->x;
}
float MyVector::getY()const{
	return this->y;
}
float MyVector::getZ()const{
	return this->z;
}
float MyVector::length() const{
	float squareX= this->x*this->x;
	float squareY= this->y*this->y;
	float squareZ= this->z*this->z;

	return sqrt(squareX+squareY+squareZ);
}
MyVector MyVector::add(const MyVector& vec){
	float xAdd=this->getX()+vec.getX();
	float yAdd=this->getY()+vec.getY();
	float zAdd=this->getZ()+vec.getZ();

	MyVector result=MyVector(xAdd,yAdd,zAdd);
	return result;
}
MyVector MyVector::subtract(const MyVector& vec){
	MyVector result=MyVector(this->x-vec.getX(),this->y-vec.getY(),this->z-vec.getZ());
	return result;
}
MyVector MyVector::mult(float scale){
	MyVector result=MyVector(this->x*scale,this->y*scale,this->z*scale);
	return result;
}
float MyVector::dot(const MyVector& vec){
	return (this->x*vec.getX()+this->y*vec.getY()+this->z*vec.getZ());
}
MyVector MyVector::cross(const MyVector& vec){
	MyVector result=MyVector(	this->y*vec.getZ()-this->z*vec.getY(),
								this->z*vec.getX()-this->x*vec.getZ(),
								this->x*vec.getY()-this->y*vec.getX());
	return result;
}
float MyVector::angle(const MyVector& vec){
	return acos(this->dot(vec)/(this->length()*vec.length()))*180.0/PI;
}
float MyVector::area(const MyVector& vec){
	MyVector crossAB=  this->cross(vec);
	return crossAB.length();
}
bool MyVector::isOrthogonal(const MyVector& vec){
	//eliminating zero-vectors
	if (	(vec.getX()==0	&& 	vec.getY()==0 	&& vec.getZ()==0 )||
			(this->x ==0 	&&	this->y ==0 	&& this->z==0)){
		return false;
	}
	else{
		if(this->dot(vec)==0){
			return true;
		}
	}
	return false;
}
bool MyVector::isParallel(const MyVector& vec){
	float scaleVec;
	if(this->x!=0){
		scaleVec=vec.getX()/this->x;
		if(this->y*scaleVec==vec.y){
			if(this->z*scaleVec==vec.z){
				return true;
			}
		}
	}
	else{
		if(vec.getY()==0 && vec.getZ()==0){
			//Nullvektor
			return true;
		}
	}
	return false;
}
MyVector::~MyVector(){}
