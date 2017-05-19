#include<iostream>
#include <assert.h>
#include "List.h"
using namespace std;

int main(){
	LinkedList one;
	one.addElement(7);
	one.addElement(10);
	one.addElement(15);
	one.addElement(5);
	one.addElement(7);
	one.addElement(8, 8);
	cout << endl << endl;
	one.print();

	one.removeElement(3);
	one.print();

	system("pause");
	return 0;
}