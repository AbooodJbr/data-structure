#include <iostream>
#include "CircularlinkedList-functions.cpp"
using namespace std;

int main() {
	CircularList<int> list, l2;
	list.add(50);
	list.add(40);
	list.add(30);
	list.add(20);
	l2.add(6);
	l2.append(list);
	cout<<list.front();
	cout << endl;
	cout << list.back() << endl;
	list.displayList();
	cout << list.size() << endl;
	l2.displayList();
}