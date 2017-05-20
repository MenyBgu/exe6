/*MenyBuganim 302490610 & BaruchRothkoff 311603252*/
#include<iostream>
using namespace std;

#ifndef LinkedList_H
#define LinkedList_H

static int counter = NULL;

class Node{
	friend class LinkedList;
private:
	Node*next;
	int value;
	int id;
public:
	Node(){}
	Node(const Node&copy){
		next = copy.next;
		value = copy.value;
		id = copy.id;
	}
	int getValue(){ return value; }
	int getId(){ return id; }
	void setId(int id){ this->id = id; }
	Node*getNext(){return next; }
	~Node(){}
};

class LinkedList{
	Node*head;
public:
	LinkedList(){}
	~LinkedList();
	Node* getHead(){ return head; }
	bool addElement(const int newVal);
	bool addElement(const int newVal, int index);
	bool addElement(const Node *newNode);
	bool removeElement(int index);
	bool removeFirstElement();
	void print();
	int size();
};
#endif // !LinkedList_H
