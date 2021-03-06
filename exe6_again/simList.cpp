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
	Node*temp = listToReverse.getHead();	

	while (temp != NULL){
		newList->addElement(temp);
		temp = temp->getNext();
	}
	cout << endl << endl;
	return newList;
}

LinkedList*removeOddItems(LinkedList&listToCut){		//remove odd.
	LinkedList*newList = new LinkedList();
	assert(newList != NULL&&"Error,heap memory.");
	Node*temp = listToCut.getHead();
	int i = 0;
	while (temp != NULL){								//check odd.
		if (i % 2 == 0){
			newList->addElement(temp);
		}
		temp = temp->getNext();
		i++;
	}
	cout << endl << endl;

	return newList;
}