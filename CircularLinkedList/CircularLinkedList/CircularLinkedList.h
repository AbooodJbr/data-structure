#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
	T data;
	Node* next;

	template <typename T>
	friend class CircularList;
};

template <typename T>
class CircularList {
private:
	Node<T>* cursor;
	int n;
	Node<T>* createNode(const T& item);

public:
	CircularList();
	CircularList(const CircularList& obj);
	CircularList<T> operator=(const CircularList& obj);
	~CircularList();
	bool operator==(const CircularList& obj);
	bool empty()const;
	int size() const;
	void add(const T& item);
	void remove();
	void removeAll();
	

	T front() const;
	T back() const;

	void advance();
	void displayList();
	void append(const CircularList& obj);

};

