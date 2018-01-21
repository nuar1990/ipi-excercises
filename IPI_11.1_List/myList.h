/*
 * myList.h
 *
 *  Created on: Jan 19, 2018
 *      Author: nuar
 */

#ifndef MYLIST_H_
#define MYLIST_H_
#include <cstddef>
#include <iterator>

class MyList {
private:
	class Node{
	public:
		int data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;

public:
	MyList():head(NULL),tail(NULL){};
	~MyList(){}

	void push_back(int val){
		Node* n= new Node(); //create new Node to be added
		n->data=val; //set data according to value in parameter
		n->prev=tail; //assign prev. node to last tail
		if(n->prev!=NULL)n->prev->next=n;//Assign this node as the follower of the previous
		n->next=NULL; //This is the end of the list;
		if(head==NULL) head=n; //exception for first list element
		tail=n; //make the new node the new tail
	}
	Node* first() const{
		return head;
	}
	Node* last() const{
		return tail;
	}
	bool isEmpty(){
		if(head==NULL&&tail==NULL) return true;
		else return false;
	}
	//deletes all contents of the list
	void remove(){
		Node* next=head;
		while(next){
			Node* deleteNo=next;
			next=next->next;
			delete deleteNo;
		}
		head=NULL;
		tail=NULL;
	}

	//requirements for input_iterator_tag must be met
	//defining full functionality as according to docu
	class Iterator:public std::iterator<std::input_iterator_tag,Node>{
	private:
		Node* current;
	public:
		Iterator(MyList::Node* x):current(x){};
		Iterator(const Iterator& mit):current(mit.current){};
		Iterator& operator++(){
			current=current->next;
			return *this;
		}
		Iterator operator++(int) {Iterator tmp(*this);operator++(); return tmp;}
		bool operator==(const Iterator& rhs)const {return current->data==rhs.current->data;}
		bool operator!=(Iterator rval){ return !(current==rval.current);}
		Node& operator*(){return *current;}
		int printValue(){
			return this->current->data;
		}
	};
};


#endif /* MYLIST_H_ */
