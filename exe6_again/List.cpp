#include<iostream>
#include"List.h"
#include <assert.h>
using namespace std;

LinkedList::~LinkedList(){
	//TODO destructor.
}

bool LinkedList::addElement(const int newVal){
	Node*temp = head;

	temp = head;
	while (temp != '\0'){
		if (temp->value == newVal){
			cout << "same value is allready exist." << endl;
			return false;
		}
		temp = temp->next;
	}

	temp = head;			//temp hold the list.

	head = new Node();		//header get new value and return to hold the list.
	assert(head != 0 && "Error,heap memory.");

	head->value = newVal;
	head->next = temp;

	temp = head;

	temp->id = ++counter;	//give uniqe id to each counter.
	cout << "new element : < " << temp->id << " , " << temp->value << " >" << endl;
	return true;
}

bool LinkedList::addElement(const int newVal, int index){
	Node*temp = head;
	bool iT = 0;
	while (temp != NULL){
		if (temp->value == newVal){				//if same value, return false.
			cout << "same value is allready exist." << endl;
			return false;
		}
		if (temp->id == index){					//check if we have the wanted index.
			iT = true;
		}
		temp = temp->next;
	}

	if (!iT){									//if we don't have the index return false.
		cout << "Error in index." << endl;
		return false;
	}
	else{
		temp = head;
		while (temp != NULL){
			if (temp->id == index){
				Node*temp2 = new Node();
				assert(temp2 != 0 && "Error, heap memory.");
				temp2->value = newVal;
				temp2->id = ++counter;
				cout << "new element : < " << temp2->id << " , " << temp2->value << " >" << endl;
				temp2->next = temp->next;
				temp->next = temp2;					//to add the new element i first created temp2 and put all we need in him, then connect him to the linkedlist.
				return true;
			}
			temp = temp->next;
		}
	}
}

bool LinkedList::removeElement(int index){
	if (head == NULL){
		cout << "list is empty." << endl;
		return false;
	}
	else if (head->id == index&&index==1){						//in case we have only 1 element and its the header.
		cout << "delete : < " << head->id << " , " << head->value << " >" << endl;
		delete head;
	}
	Node*temp = head;
	bool check = 0;
	while (temp != NULL){						//checking first we have wanted index(id) here.
		if (temp->id == index){
			check = 1;
		}
		temp = temp->next;
	}
	if (!check){
		cout << "Error in index." << endl;
		return false;
	}
	temp = head;
	while (temp->next->id != index)
		temp = temp->next;
	Node*temp2 = temp->next;					//create temp2 to stand above what we want to delete.
	temp->next = temp->next->next;			//moving 2 forward.
	cout << "delete : < " << temp2->id << " , " <<temp2->value << " >" << endl;
	delete temp2;
	return true;
}

bool LinkedList::removeFirstElement(){

}

void LinkedList::print(){							//print function.
	if (head == NULL){
		cout << "list is empty." << endl;
	}
	Node*temp = head;
	while (temp != NULL){
		cout << "new element : < " << temp->id << " , " << temp->value << " >" << endl;
		temp = temp->next;
	}

}
