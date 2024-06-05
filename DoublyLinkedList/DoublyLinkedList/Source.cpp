#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList-functions.cpp"
using namespace std;



int main() {
	DoublyList<int> list, l;
	cout << list.empty() << endl;
	list.addFront(4);
	list.addBack(9);
	list.addFront(5);
	list.displayList();
	list.insertBefore(4, 66);
	list.displayList();
	list.insertAfter(4, 77);
	list.displayList();
	cout << list.isAvailable(77) << "\t" << list.isAvailable(4) << endl;
	list.displayList();
	list.displayList();
	list.divide(l);
	list.displayList();
	l.displayList();

	DoublyList<string> str;
	str.addBack("rty");
	str.displayList();
	cout << list.average() << endl;
	cout << list.max() << endl;
	cout << list.min() << endl;

}