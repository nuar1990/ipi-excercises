//============================================================================
// Name        : Turingmaschine.cpp
// Author      : Nuar(Frank Streicher)
// Version     : 0.9
// Copyright   : Open
// Description : Exercise IPI_WS2017
//============================================================================

#include <iostream>
#include <vector>
/*
 * Die Schwierigkeit in der Aufgabe besteht darin, eine korrekte Darstellung der Berechnung in einer
 * Turing Maschine darzustellen.
 * Mit der Hochsprache C++, kann man die Problemstellung mit den richtigen Datenstrukturen komplett umgehen
 * und zu einem richtigen Ergebnis kommen.
 *  Daher folgen hier verschiedene Methoden, die das Problem anhand des Realbeispiels lösen.
 */

void partA(){
	unsigned int m,n;
	bool end=0;
	std::cout<<"a)"<<std::endl;
	std::cout<<"Insert amount of numbers m,n >=1 representing 1's on the simple touring machine:"<<std::endl;
	std::cout<<"m: "<<std::endl;
	std::cin>>m;
	std::cout<<"n: "<<std::endl;
	std::cin>>n;
	unsigned int band[m+n+2];
	unsigned int aCase= 1;
	for(unsigned int i=0; i<m ; i++){band[i]=1;}
	band[m]=0;
	for(unsigned int i=m+1; i<m+n+1; i++){band[i]=1;}
	band[m+n+1]=0;


	unsigned int index=0;
	unsigned int sizeBand = *(&band + 1) - band;

	std::cout<<"(x) indicates the position of the reading head:"<<std::endl;
	while(!end){
		for(unsigned int i=0;i<sizeBand; i++){
			if(index==i){
				std::cout<<"("<<band[i]<<")|";
			}
			else{
				std::cout<<band[i]<<'|';
			}
		}
		std::cout<<" Case:"<<aCase<<std::endl;
		switch(aCase){

			//Case: 1, Entry: 1 , Output:0, Next Case:2
			case 1:
				band[index]=0;
				aCase=2;
				index++;
				break;

			//Case: 2, Entry: 1, Output:1, Next Case:2
			//Case: 2  Entry: 0, Output:1,  Next Case: 3
			case 2:
				if(band[index]!=0){
					band[index]=1;
				}
				else{
					band[index]=1;
					aCase=3;
				}
				index++;
				break;

			//Case: 3, Entry: 1, Output:1, Next Case: 3
			//Case: 3, Entry: 0, Output:0, Direction: Left, Next Case: 4
			case 3:
				if(band[index]!=0){
					band[index]=1;
					index++;
				}
				else{
					band[index]=0;
					aCase=4;
					index--;
				}

				break;
			//Case: 4, Entry: 1, Output:0 , Direction: Left Next Case: 5
			case 4:
				band[index]=0;
				aCase=5;
				index--;
				break;
			//Case: 5, Entry: 1, Output:1, Direction: Left Next Case: 5
			//Case: 5, Entry: 0, Output:1; Direction: None, Next Case: end
			case 5:
				if(band[index]!=0){
					band[index]=1;
					index--;
				}
				else{
					band[index]=1;
					end=true;
				}
				break;
		}
	}
	for(unsigned int i=0;i<sizeBand; i++){
		if(index==i){
			std::cout<<"("<<band[i]<<")|";
		}
		else{
			std::cout<<band[i]<<'|';
		}
	}
	std::cout<<" Case:"<<aCase<<std::endl;
}
void part0(){
	unsigned int n;
	unsigned int m;
	std::vector <unsigned int> mVector;
	std::vector <unsigned int> nVector;
	std::vector <unsigned int> turingVector;
	std::vector <unsigned int> turingVector2;

	//a) vector: optimal representation
	std::cout<<"a)"<<std::endl;
	std::cout<<"Insert quantity m,n >=1 representing 1's on the simple touring machine:"<<std::endl;
	std::cout<<"m: "<<std::endl;
	std::cin>>m;
	if (std::cin.fail()||m==0){
		std::cout<<"Type mismatch occured, please enter a natural number >=1"<<std::endl;
		return;
	}
	std::cout<<"n: "<<std::endl;
	std::cin>>n;
	if (std::cin.fail()||n==0){
		std::cout<<"Type mismatch occured, please enter a natural number >=1"<<std::endl;
		return;
	}

	for(unsigned int i=0; i<m;i++){mVector.push_back(1);}
	for(unsigned int i=0; i<n;i++){nVector.push_back(1);}

	std::vector<unsigned int>::iterator it= turingVector.begin();
	std::vector<unsigned int>::iterator it1= mVector.begin();
	std::vector<unsigned int>::iterator it2= mVector.end();

	turingVector.insert(it,it1,it2);
	it=turingVector.end();
	turingVector.insert(it,0);

	it= turingVector.end();
	it1= nVector.begin();
	it2= nVector.end();

	turingVector.insert(it,it1,it2);


	std::cout<<"The following band:"<<std::endl;
	for(std::vector<unsigned int>::iterator it= turingVector.begin(); it!= turingVector.end(); ++it){
		std::cout << '|' << *it;
	}
	std::cout<< '|'<<std::endl;
	std::cout<< "reads as: "<<std::endl;
	for(std::vector<unsigned int>::iterator it=turingVector.begin();it!=turingVector.end();++it){
		if(*it==1){std::cout << '+' << *it;}
	}
	std::cout<<std::endl;
	unsigned int sum=0;
	for(std::vector<unsigned int>::iterator it=turingVector.begin();it!=turingVector.end();++it){
		if(*it==1){sum +=1;}
	}
	std::cout<< "representing the decimal number: "<<sum<<std::endl;
	std::cout<< "On the band:"<<std::endl;
	for(unsigned int i=0;i<sum;i++){ turingVector2.push_back(1);}
	it=turingVector.end();
	it1=turingVector2.begin();
	it2=turingVector2.end();
	turingVector.insert(it,0);
	it=turingVector.end();
	turingVector.insert(it,it1,it2);
	for(std::vector<unsigned int>::iterator it= turingVector.begin(); it!= turingVector.end(); ++it){
		std::cout << '|' << *it;
	}

	return ;
}
void partB(){
	unsigned int n;
	bool end=0;
	std::cout<<"b)"<<std::endl;
	std::cout<<"Insert amount of numbers n >=1 representing 1's on the simple touring machine:"<<std::endl;
	std::cout<<"n: "<<std::endl;
	std::cin>>n;
	unsigned int band[3*n];
	unsigned int aCase= 1;
	for(unsigned int i=0;i<n;i++){band[i]=0;}
	for(unsigned int i=n; i<2*n; i++){band[i]=1;}
	for(unsigned int i=2*n; i<3*n; i++){band[i]=0;}


	unsigned int index=n;
	unsigned int sizeBand = *(&band + 1) - band;

	std::cout<<"(x) indicates the position of the reading head:"<<std::endl;
	while(!end){
		for(unsigned int i=0;i<sizeBand; i++){
			if(index==i){
				std::cout<<"("<<band[i]<<")|";
			}
			else{
				std::cout<<band[i]<<'|';
			}
		}
		std::cout<<" Case:"<<aCase<<std::endl;
		switch(aCase){

			//Case: 1, Entry: 1 , Output:0,Direction:Left, Next Case:2
			//Case: 1, Entry: 0, Output:0,Direction: none, Next Case:end
			case 1:
				if(band[index]!=0){
					band[index]=0;
					aCase=2;
					index--;
				}
				else{
					//in theory: the machine has to parse back until it finds another zero, which is out of scope
					//in this example, therefore I chose to manually put the head back into place.
					//it would be a simple matter of resizing the array however - cba
					index=0;
					end=true;
				}
				break;

			//Case: 2, Entry: 1, Output:1,Direction:Left, Next Case:2
			//Case: 2  Entry: 0, Output:1,Direction:Right, Next Case: 3
			case 2:
				if(band[index]!=0){
					band[index]=1;
					index--;
				}
				else{
					band[index]=1;
					aCase=3;
					index++;
				}
				break;

			//Case: 3, Entry: 1, Output:1, Direction: Left, Next Case: 3
			//Case: 3, Entry: 0, Output:1, Direction: Right, Next Case: 1
			case 3:
				if(band[index]!=0){
					band[index]=1;
					index++;
				}
				else{
					band[index]=1;
					aCase=1;
					index++;
				}
				break;
		}
	}
	for(unsigned int i=0;i<sizeBand; i++){
		if(index==i){
			std::cout<<"("<<band[i]<<")|";
		}
		else{
			std::cout<<band[i]<<'|';
		}
	}
	std::cout<<" Case:"<<aCase<<std::endl;
}

int main(){
	bool end=0;
	char exercise;
	while (!end){
		std::cout<< "Which part of the exercise? (type 'a' or 'b')"<<std::endl;
		std::cin>>exercise;
		if(exercise=='a'){
            partA();
			end=1;
		}
		else if(exercise=='b'){
			partB();
			end=1;
		}
		else{
			std::cout<<"Not a valid entry, shutting down."<<std::endl;
			end=1;
		}
	}
	return 0;
}
