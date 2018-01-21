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
	while(!crypted.eof()){
		crypted>>c;
		//c=std::tolower(c); //If possible make lowercase, else char unchanged
		if(c<65 || c>122 || (c>90&&c<97)) continue; //ignoring everything but letters.
		std::map<char,int>::iterator it=count.find(c);
		std::pair<std::map<char,int>::iterator,bool> ret;

		if(it==count.end()) count.insert(std::pair<char,int>(c,1));
		else count.insert(std::pair<char,int>(c,it->second++));
	}
	//c)
	std::map<int,char> sorted;
	for(auto it=count.begin();it!=count.end();++it){
		sorted.insert(std::pair<int,char>(it->second,it->first));
	}
	//req. c++11 or later
	std::vector<char> letters= {'z','q','x','j','k','v','b','p','y','g','f','w','m','u','c','l','d','r','h','s','n','i','o','a','t','e'};
	std::vector<char> firstLetters= {'x','z','q','k','j','y','v','u','g','n','l','e','r','d','m','f','h','p','b','c','w','s','i','o','a','t'};
	//d
	std::map<char,char> decrypt;

	int distU=0;
	int distL=0;
	for(auto it=sorted.begin();it!=sorted.end();++it){
		//upper-case
		if(it->second<91){
			decrypt.insert(std::pair<char,char>(it->second,std::toupper(firstLetters[distU])));
			distU++;
		}
		//lower-case
		if(it->second>96){
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

	for(auto it=sorted.begin();it!=sorted.end();++it){
		std::cout<< it->first<<" => "<<it->second<<"\n";
	}
	for(auto it=decrypt.begin();it!=decrypt.end();++it){
		std::cout<< it->first<<" => "<<it->second<<"\n";
	}
	return 0;
}

