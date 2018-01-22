/*
 * decrypt.cc
 *
 *  Created on: Jan 21, 2018
 *      Author: nuar
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main(){
	//a)
	std::ifstream crypted("encrypted_text.txt");
	//b)
	std::map<char,int> count;
	char c;
	int upper=0,lower=0;
	while(!crypted.eof()){
		crypted>>c;
		if(!std::isalpha(c)) continue; //ignoring everything but letters.
		std::map<char,int>::iterator it=count.find(c);
		std::pair<std::map<char,int>::iterator,bool> ret;

		if(it==count.end()) {
			count.insert(std::pair<char,int>(c,1));
			if(std::isupper(c)) upper++;
			else lower++;
		}
		else count.insert(std::pair<char,int>(c,it->second++));
	}
	//c) the exercise doesn't advise for the right kind of STL container
	// got to use a multimap here - since it's possible that
	// multiple characters have identical occurrences,
	// regular map doesn't allow for duplicate values under the same key
	std::multimap<int,char> sorted;
	for(auto it=count.begin();it!=count.end();++it){
		sorted.insert(std::pair<int,char>(it->second,it->first));
	}
	//requires c++11 or later
	std::vector<char> letters= {'j','z','q','x','k','v','b','y','g','p','w','f','m','c','u','l','d','r','h','i','s','n','o','a','t','e'};
	std::vector<char> firstLetters= {'k','x','z','q','u','j','v','g','d','y','r','f','e','o','p','m','l','h','b','s','w','a','c','t','n','i'};

	//d
	std::map<char,char> decrypt;

	//variables for accessing proper element in vectors, dynamic according to how many characters occure.
	int distU=upper-firstLetters.size();
	int distL=lower-letters.size();

	for(auto it=sorted.begin();it!=sorted.end();++it){
		//upper-case
		if(std::isupper(it->second)){
			decrypt.insert(std::pair<char,char>(it->second,std::toupper(firstLetters[distU])));
			distU++;
		}
		//lower-case
		if(std::islower(it->second)){
			decrypt.insert(std::pair<char,char>(it->second,letters[distL]));
			distL++;
		}
	}
	//e
	std::ofstream decrypted("decrypted_text.txt");
	std::fstream encrypted("encrypted_text.txt",std::ios::in);
	std::string line;

	while(std::getline(encrypted,line)){
		for(auto it=line.begin();it!=line.end();++it){
			std::map<char,char>::iterator iter=decrypt.find(*it);
			if(iter==decrypt.end()) decrypted<<*it;
			else decrypted<<decrypt[*it];
		}
		decrypted<<"\n";
	}
	return 0;
}

