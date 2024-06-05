#pragma once
#include <iostream>
using namespace std;
//in this header file we implemented the DS 'HASH'
//ps.: we handeled collision here using 'Chaining Method'
class Node {
	int data;
	Node* next;
	friend class Hash;
public: Node() { next = NULL; }
};

class Hash {
private : 
	Node** hash; int capacity, n;
	int h(int x) {
		return abs(x) % capacity;
	}
public :
	Hash(int cap = 11) {
		capacity = cap;
		n = 0;
		hash = new Node * [capacity] {NULL};
	}

	~Hash() {
		for (int i = 0; i < capacity; ++i) {
			Node* current = hash[i];
			while (current) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}
		delete[] hash;
	}

	int size() { return n; }
	
	void insert(int x) {
		int b = h(x);
		Node* p = new Node;
		p->data = x;
		p->next = hash[b];
		hash[b] = p;
		n++;
	}

	Node* findLocation(int x) {
		int b = h(x);
		if (hash[b] == NULL) return NULL;
		Node* p = hash[b];
		while (p) {
			if (p->data == x) return p;
			p = p->next;
		}
		return NULL;
	}

	bool find(int x) {
		int b = h(x);
		if (hash[b] == NULL) return false;
		Node* p = hash[b];
		while (p) {
			if (p->data == x) return true;
			p = p->next;
		}
		return false;
	}

	bool remove(const int& x) {
		int b = h(x);
		Node* p = findLocation(x);
		if (!p) return false;

		if (p == hash[b]) {
			Node* old = hash[b];
			hash[b] = hash[b]->next;
			old->next = NULL;
			delete old;
			n--;
			return true;
		}

		else if (p->next == NULL) {
			Node* last, * b4;
			last = b4 = hash[b];
			while (last && last->next) {
				b4 = last;
				last = last->next;
			}
			delete last;
			b4->next = NULL;
			n--;
			return true;
		}

		else {
			
			Node* q = hash[b];
			while (q->next != p) q = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
			n--;
		}
		return true;
	}

};