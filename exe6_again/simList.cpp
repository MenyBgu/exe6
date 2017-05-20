/*MenyBuganim 302490610 & BaruchRothkoff 311603252*/
#include<iostream>
#include <assert.h>
#include "List.h"
using namespace std;

LinkedList*reverseList(LinkedList & listToReverse);
LinkedList*removeOddItems(LinkedList&listToCut);

int main(){
	std::cout << "========================================================" << std::endl;		
	std::cout << "Meny Buganim  302490610 ---- Baruch Rothkoff  311603252" << std::endl;
	std::cout << "========================================================" << std::endl << std::endl;

	int clicks;								//num of input's from user.
	cout << "please type how many node you want: " << endl;
	cin >> clicks;
	while (cin.fail()||clicks<=0){			//validation.
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << "type number above 0 please." << endl;
		cin >> clicks;
	}

	LinkedList a;							//first list.
	int x; bool y;							//boolean to check if allright from functions. if not ask again input.
	for (int i = 0; i < clicks; i++){
		cout << "please enter number: ";
		cin >> x;
		while (cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Error, type number please." << endl;
			cin >> x;
		}
		y=a.addElement(x);
		while (!y){
			y = 1;
			cout << "please enter other number: " << endl;
			cin >> x;
			while (cin.fail()){
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error, type number please." << endl;
				cin >> clicks;
			}
			y = a.addElement(x);
		}
	}
	cout << "original list: " << endl;		//print original.
	a.print();
	cout << endl;

	LinkedList *b = reverseList(a);			//print reverse.
	cout << "reverse list: " << endl;
	b->print();
	cout << endl;

	LinkedList *c = removeOddItems(a);		//print even.
	cout << "removeOddItems list: " << endl;
	c->print();
	cout << endl;

	delete b;								//release memory.
	delete c;

	system("pause");
	return 0;
}

LinkedList*reverseList(LinkedList & listToReverse){
	LinkedList *newList = new LinkedList();					//reverse. 
	assert(newList != NULL&&"Error,heap memory.");
	//Node*current = newList->getHead();
	Node*temp = listToReverse.getHead();	

	while (temp != NULL){
		newList->addElement(temp->getValue());
		//current->setId(temp->getId());
		temp = temp->getNext();
	}
	cout << endl << endl;
	return newList;
}

LinkedList*removeOddItems(LinkedList&listToCut){		//remove odd.
	LinkedList*newList = new LinkedList();
	assert(newList != NULL&&"Error,heap memory.");
	//Node*current = newList->getHead();
	Node*temp = listToCut.getHead();
	int i = 0;
	while (temp != NULL){								//check odd.
		if (i % 2 == 0){
			newList->addElement(temp->getValue());
		//	current->setId(temp->getId());
		//	current->getNext();
		}
		temp = temp->getNext();
		i++;
	}
	cout << endl << endl;

	return newList;
}

/*#include <iostream> 
#include "List.h"
using namespace std;
#include <cassert>
#include <string>


LinkedList * reverseList(LinkedList &listToReverse){
	LinkedList *newlist = new LinkedList();
	assert(newlist != 0);
	Node *pop = listToReverse.getHead();
	for (int i = 1; i <= listToReverse.size(); i++){
		(*newlist).addElement((*pop).getValue());
		pop = (*pop).getNext();
	}
	return newlist;
}

LinkedList * removeOddItems(LinkedList &listToCut){
	LinkedList *newlist = new LinkedList();
	assert(newlist != 0);
	Node *pop = listToCut.getHead();
	for (int i = 1; i <= listToCut.size(); i++){
		if (i % 2 == 1){
			(*newlist).addElement((*pop).getValue());
		}
		pop = (*pop).getNext();
	}
	LinkedList *newlist2 = reverseList(*newlist);
	return newlist2;
}

int main()
{

	cout << "EXE6: Matan chibotero 204076962, liel levi 307983320" << endl;
	cout << "******************" << endl;
	bool b;
	LinkedList a;
	int x, num;
	cout << "Please enter the number of nodes:";
	cin >> x;
	while (x <= 0){
		cout << "Size no can to be <=0\nEnter again the size of list:" << endl;
		cin >> x;
	}
	cout << "Please enter the nodes data (intiger) :";
	cin >> num;
	cin.ignore(500, '\n');
	a.addElement(num);
	cout << "number=" << num << ",id=" << a.getHead()->getId() - 1 << endl;
	for (int i = 1; i <x; i++){
		cout << "Please enter the nodes data (intiger) :";
		cin >> num;
		cin.ignore(500, '\n');
		b = a.addElement(num, i);
		while (b == false){
			cout << "An existing number in the list\nEnter number in location:";
			cin >> num;
			b = a.addElement(num, i);
		}
		cout << "number=" << num << ",id=" << a.getHead()->getId() - 1 << endl;

	}
	cout << "the original list:";
	a.print();
	LinkedList *l = reverseList(a);
	cout << "the reversed list:";
	l->print();
	LinkedList *k = removeOddItems(a);
	cout << "the even nodes of the list is:";
	k->print();
	delete k;
	delete l;
	cin.get();
	return 0;
}*/