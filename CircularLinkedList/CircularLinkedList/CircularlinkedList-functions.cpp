#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

template <typename T>
Node<T>* CircularList<T>::createNode(const T& item) {
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	return newNode;
}

template <typename T>
CircularList<T>::CircularList() {
	cursor = new Node<T>;
	cursor->next = cursor;

	n = 0;
};


template <typename T>
CircularList<T>::CircularList(const CircularList& obj) {
	if (obj.empty()) exit(1);
	for (int i= 0; i <= n; i++) {
		Node<T>* ptr = cursor;
		add(ptr->data);
		advance();
	}
};



template <typename T>
CircularList<T> CircularList<T>::operator=(const CircularList& obj) {
	if (!obj.empty()) {
	if(!(*this == obj)) {
			for (int i = 0; i <= n; i++) {
				Node<T>* ptr = cursor;
				add(ptr->data);
				advance();
			}
		}
	}
	return *this;
}

template <typename T>
bool CircularList<T>::operator==(const CircularList& obj) {
	if (!obj.empty()) {
		if (n == obj.n) {
			for (int i = 0; i < n; i++) {
				if (cursor->data != obj.cursor->data)
					return false;
			}
			return true;
		}
	}
	return false;
}

template <typename T>
CircularList<T>::~CircularList() {
	removeAll();
	delete cursor;
	cursor = NULL;
}

template <typename T>
bool CircularList<T>::empty() const{
	return n==0;
}

template <typename T>
int CircularList<T>::size() const{
	return n;
}


template <typename T>
void CircularList<T>::add(const T& item) {
	if (empty()) {
		cursor->data = item;
		cursor->next = cursor;
	}
	else{
		Node<T>* newNode = createNode(item);
		newNode->next = cursor->next;
		cursor->next = newNode;
	}
	n++;
};

template <typename T>
void CircularList<T>::remove() {
	if (empty()) exit(1);

	Node<T>* deletedNode = cursor->next;
	cursor->next = deletedNode->next;
	deletedNode->next = NULL;
	delete deletedNode;
	n--;
}



template <typename T>
void CircularList<T>::removeAll() {
	if (empty()) exit(1);
	while (cursor->next != cursor) {
		remove();
	}
}




template <typename T>
T CircularList<T>::front() const {
	if (empty()) exit(1);
	return cursor->next->data;
}

template <typename T>
T CircularList<T>::back() const {
	if (empty()) exit(1);
	return cursor->data;
}



template <typename T>
void CircularList<T>::advance() {
	if (empty()) exit(1);
	cursor = cursor->next;
}

template <typename T>
void CircularList<T>::displayList() {
	cout << "(" << n << ")  [ ";
		for (int i = 0; i < n; i++)
		{	if(i==n-1)
			{
				cout << cursor->next->data << " ]";
			}
			else{
			cout << cursor->next->data << " , ";
			advance();
			}
		}
	
	cout << endl;
}

template <typename T>
void CircularList<T>::append(const CircularList& obj) {
	if (empty()) {
		*this = obj;
	}
	else {
		for (int i = 0; i < obj.n; i++) {
			add(obj.cursor->next->data);
			advance();
		}
	}
}