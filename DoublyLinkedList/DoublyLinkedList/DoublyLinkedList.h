#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DNode {
private:
	T data;
	DNode* prev;
	DNode* next;

	template <typename T>
	friend class DoublyList;
};

template <typename T>
class DoublyList {
private:
	int n;
	DNode<T>* header;
	DNode<T>* trailer;
	DNode<T>* find(const T& item) const;
	DNode<T>* createNode(const T& item) const;
	void swapByNodes(DNode<T>* a, DNode<T>* b);

public:
	DoublyList();

	DoublyList(const DoublyList& obj);

	~DoublyList();

	DoublyList<T>& operator=(const DoublyList<T>& obj);

	bool empty() const;

	inline int size() const;

	void addFront(const T& item);

	void addBack(const T& item);

	bool removeFront() ;

	bool removeBack() ;

	void displayList();

	T getBack() const;

	T getFront() const;

	bool removeAll() ;

	void insertBefore(const T& that, const T& item);

	void insertAfter(const T& that, const T& item);

	bool remove(const T& item) ;

	bool isAvailable(const T& item) const;

	bool swapByValues(const T& val1, const T& val2) const;


	bool append(const DoublyList& list) const;

	void printInReverse();

	int count3charWord() const;

	bool isPalindrome() const;

	void divide(DoublyList& obj);

	double sum() const;

	double average() const;

	T max() const;

	T min() const;
};