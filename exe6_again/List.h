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
	~Node(){}
};

class LinkedList{
	Node*head;
public:
	LinkedList(){}
	~LinkedList();
	bool addElement(const int newVal);
	bool addElement(const int newVal, int index);
	bool removeElement(int index);
	bool removeFirstElement();
	void print();
	int size();
};
#endif // !LinkedList_H
