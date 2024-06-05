#include <iostream>
#include "BST.h"
using namespace std;

int main() {
	BST<int> x;
	x.insert(20);
	x.insert(15);
	x.insert(25);
	x.insert(10);
	x.insert(16);
	x.insert(22);
	x.insert(26);
	x.displayAll("LNR");


}