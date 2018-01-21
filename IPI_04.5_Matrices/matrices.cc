/*
 * matrices.cc
 *
 *  Created on: Nov 19, 2017
 *      Author: nuar
 */
#include <iostream>
#include <cmath>
#include <array>
#include <stdexcept>
#include <vector>
#include <utility>
#include <iomanip>

std::vector<std::vector<int>> matrix_zero(int a);
std::vector<std::vector<int>> matrix_id(int a);
std::vector<std::vector<int>> matrix_diagonal(std::vector<std::vector<int>> &matrix);
std::vector<std::vector<int>> matrix_add(std::vector<std::vector<int>> &a,std::vector<std::vector<int>> &b);
std::vector<std::vector<int>> matrix_subtract(std::vector<std::vector<int>> &a,std::vector<std::vector<int>> &b);
std::vector<std::vector<int>> matrix_transpose(std::vector<std::vector<int>> &matrix);
int matrix_trace(std::vector<std::vector<int>> &matrix);
std::vector<std::vector<int>> matrix_mult(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b);
void print_matrix(std::vector<std::vector<int>> &matrix);


int main(int argc, char *argv[]){
	std::vector<std::vector<int>> mA;
	std::vector<int> line1={2,5,4};
	std::vector<int> line2={3,2,4};
	std::vector<int> line3={1,1,0};
	mA.push_back(line1);
	mA.push_back(line2);
	mA.push_back(line3);

	std::vector<std::vector<int>> mB;
	std::vector<int> line4={1,2,3};
	std::vector<int> line5={4,5,6};
	std::vector<int> line6={7,8,9};
	mB.push_back(line4);
	mB.push_back(line5);
	mB.push_back(line6);

	std::vector<std::vector<int>> mZeroA=matrix_zero(mA[0].size());
	std::vector<std::vector<int>> mZeroB=matrix_zero(mB[0].size());
	std::cout<<"Nullmatrix von A und B:"<<std::endl;
	print_matrix(mZeroA);
	std::cout<<"----------------"<<std::endl;
	print_matrix(mZeroB);

	std::vector<std::vector<int>> mIdA=matrix_id(mA[0].size());
	std::vector<std::vector<int>> mIdB=matrix_id(mB[0].size());
	std::cout<<"Einheitsmatrix von A und B:"<<std::endl;
	print_matrix(mIdA);
	std::cout<<"----------------"<<std::endl;
	print_matrix(mIdB);

	std::vector<std::vector<int>> mDiagonalA=matrix_diagonal(mA);
	std::vector<std::vector<int>> mDiagonalB=matrix_diagonal(mB);
	std::cout<<"Diagonalmatrix von A und B:"<<std::endl;
	print_matrix(mDiagonalA);
	std::cout<<"----------------"<<std::endl;
	print_matrix(mDiagonalB);

	std::vector<std::vector<int>> mAdd=matrix_add(mA,mB);
	std::cout<<" A + B:"<<std::endl;
	print_matrix(mAdd);

	std::vector<std::vector<int>> mSubtract=matrix_subtract(mA,mB);
	std::cout<<" A - B:"<<std::endl;
	print_matrix(mSubtract);

	std::vector<std::vector<int>> mTransposeA=matrix_transpose(mA);
	std::vector<std::vector<int>> mTransposeB=matrix_transpose(mB);
	std::cout<<"Transponierte Matrix von A und B:"<<std::endl;
	print_matrix(mTransposeA);
	std::cout<<"----------------"<<std::endl;
	print_matrix(mTransposeB);

	std::cout<<"Spur von A:"<<matrix_trace(mA)<<"       Spur von B:"<<matrix_trace(mB)<<std::endl;

	std::vector<std::vector<int>> mMult=matrix_mult(mA,mB);
	std::cout<<"Matrixmultiplikation von A und B:"<<std::endl;
	print_matrix(mMult);

	return 0;
}
std::vector<std::vector<int>> matrix_zero(int a){
	std::vector<std::vector<int>> mZero;
	std::vector<int> line;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			line.push_back(0);
		}
		mZero.push_back(line);
		line.clear();
	}
	return mZero;
}
std::vector<std::vector<int>> matrix_id(int a){
	std::vector<std::vector<int>> mId;
	std::vector<int> line;
	int count=0;

	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(j==count){
				line.push_back(1);
			}
			else{
				line.push_back(0);
			}
		}
		mId.push_back(line);
		line.clear();
		count++;
	}
	return mId;
}
//Für jede iteration einen counter mit hochzählen, wenn iterationsschrit und counter uebereinstimme
// ->Schreibe den aus der Matrix ansonsten =0;
std::vector<std::vector<int>> matrix_diagonal(std::vector<std::vector<int>> &matrix){
	std::vector<std::vector<int>> mDiagonal;
	std::vector<int> line;
	int count=0;

	for(int i=0;i<matrix[i].size();i++){
		for(int j=0;j<matrix[i].size();j++){
			if(j==count){
				line.push_back(matrix[i].at(count));
			}
			else{
				line.push_back(0);
			}
		}
		mDiagonal.push_back(line);
		line.clear();
		count++;
	}
	return mDiagonal;
}
//easy
std::vector<std::vector<int>> matrix_add(	std::vector<std::vector<int>> &a,
											std::vector<std::vector<int>> &b){
	std::vector<std::vector<int>> mAdd;
	std::vector<int> line;
	for(int i=0;i<a[i].size();i++){
		for(int j=0;j<a[j].size();j++){
			line.push_back(a[i][j]+b[i][j]);
		}
		mAdd.push_back(line);
		line.clear();
	}
	return mAdd;
}
//str8 forward
std::vector<std::vector<int>> matrix_subtract(	std::vector<std::vector<int>> &a,
												std::vector<std::vector<int>> &b){
	std::vector<std::vector<int>> mSubtract;
	std::vector<int> line;
	for(int i=0;i<a[i].size();i++){
		for(int j=0;j<a[j].size();j++){
			line.push_back(a[i][j]-b[i][j]);
		}
		mSubtract.push_back(line);
		line.clear();
	}
	return mSubtract;
}
//Zahlen und Spalten vertauschen -->Elemente in Spalten iterieren durch korrekte indexierung
std::vector<std::vector<int>>matrix_transpose(std::vector<std::vector<int>> &matrix){
	std::vector<std::vector<int>> tMatrix;
	std::vector<int> column;
	for (int i=0;i<matrix[i].size();i++){
		for(int j=0;j<matrix[j].size();j++){
			column.push_back(matrix[j].at(i));
		}
		tMatrix.push_back(column);
		column.clear();
	}
	return tMatrix;
}
//Diagonale auslesen (s.o) und addieren.
int matrix_trace(std::vector<std::vector<int>> &matrix){
	int count=0;
	int sum=0;

	for(int i=0;i<matrix[i].size();i++){
		for(int j=0;j<matrix[j].size();j++){
			if(j==count){
				sum+=matrix[i][j];
			}
		}
		count++;
	}
	return sum;
}
/*
 * Zeihlenweise multiplizieren von A mit der Transponierten Matrix von B, wobei B innere Iteration ist
 * d.h. B laueft fuer jeden Eintrag ueber eine Zeile.
 */
std::vector<std::vector<int>> matrix_mult(	std::vector<std::vector<int>> &a,
											std::vector<std::vector<int>> &b){
	std::vector<std::vector<int>> mMult;
	std::vector<int> line;
	int sum=0;
	for(int i=0;i<a[i].size();i++){
		for(int j=0;j<b[j].size();j++){
			for(int k=0;k<b[k].size();k++){
				sum+=a[i][k]*matrix_transpose(b)[j][k];
			}
			line.push_back(sum);
			sum=0;
		}
		mMult.push_back(line);
		line.clear();
	}
	return mMult;
}
void print_matrix(std::vector<std::vector<int>> &matrix){
	for(int i=0;i<matrix[0].size();i++){
		for(int j=0;j<matrix[i].size();j++){
			std::cout<<std::setw(3)<<matrix[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
