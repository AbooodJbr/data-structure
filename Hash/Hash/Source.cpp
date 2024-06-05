#include <iostream>
#include "Hash2.h"
//#include "Hash1.h"
using namespace std;

int main() {
	Hash h;
	h.insert(40);
	h.insert(55);
	h.insert(64);
	h.insert(78);
	h.insert(87);
	cout << h.size() << endl;
	h.remove(64);
	h.remove(87);
	cout << h.size() << endl;
	cout << h.findLocation(40) << endl;
	cout << h.findLocation(55) << endl;
	cout << h.findLocation(64) << endl;
	cout << h.findLocation(78) << endl;
	cout << h.findLocation(87) << endl;
	cout << h.find(40) << endl << h.find(35) << endl;
}


/*
int main() {
	Hash h;
	h.insert("int");
	h.insert("float");
	h.insert("double");
	h.insert("long long");
	cout << h.find("long long") << endl;
	cout << h.remove("long long") << endl;
	cout << h.remove("short") << endl;
	cout << h.find("long long") << endl;
}*/