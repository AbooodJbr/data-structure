#include <iostream>
#include "DoublyLinkedList.h";
using namespace std;



	template <typename T>
	DNode<T>* DoublyList<T>::find(const T& item) const {
		if (empty()) return NULL;
		DNode<T>* p = header->next;
		while (p != trailer && p->data != item) {
			p = p->next;
		}
		if (p == trailer) return NULL;
		return p;
	}

	template <typename T>
	DNode<T>* DoublyList<T>::createNode(const T& item) const {
		DNode<T>* newNode = new DNode<T>;
		newNode->data = item;
		return newNode;
	}

	template <typename T>
	void DoublyList<T>::swapByNodes(DNode<T>* a, DNode<T>* b) {
		if (a->next == b) {
			DNode<T>* before = a->prev, * after = b->next;

			a->next = after;
			after->prev = a;
			a->prev = b;
			b->next = a;
			before->next = b;
			b->prev = before;
		}
		else if (b->next == a) {
			DNode<T>* before = b->prev, * after = a->next;

			b->next = after;
			after->prev = b;
			b->prev = a;
			a->next = b;
			before->next = a;
			a->prev = before;
		}
		else {
			DNode<T>* beforeA = a->prev, * afterA = a->next;
			DNode<T>* beforeB = b->prev, * afterB = b->next;

			beforeA->next = b;
			b->prev = beforeA;
			afterA->prev = b;
			b->next = afterA;

			beforeB->next = a;
			a->prev = beforeB;
			afterB->prev = a;
			a->next = afterB;
		}
	}

	template <typename T>
	DoublyList<T>::DoublyList() {
		header = new DNode<T>;
		trailer = new DNode<T>;
		header->next = trailer;
		trailer->prev = header;
		n = 0;
	}

	template <typename T>
	DoublyList<T>::DoublyList(const DoublyList& obj) {
		header = new DNode<T>;
		trailer = new DNode<T>;
		header->next = trailer;
		trailer->prev = header;
		DNode<T>* p = obj.header->next;
		while (p != obj.trailer) {
			addBack(p->data);
			p = p->next;
		}
		n = obj.n;
	}

	template <typename T>
	DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& obj) {
		if (this != &obj) { 
			if (!empty()) {
				removeAll();
			}
			DNode<T>* p = obj.header->next;
			while (p != obj.trailer) {
				addBack(p->data);
				p = p->next;
			}
		}
		return *this;  
	}

	template <typename T>
	inline bool DoublyList<T>::empty() const { return header->next == trailer; }

	template <typename T>
	inline int DoublyList<T>::size() const { return n; }

	template <typename T>
	void DoublyList<T>::addFront(const T& item) {
		DNode<T>* newNode = createNode(item);

		newNode->next = header->next;
		header->next->prev = newNode;
		newNode->prev = header;
		header->next = newNode;
		n++;
	}

	template <typename T>
	void DoublyList<T>::addBack(const T& item) {
		DNode<T>* newNode = createNode(item);

		newNode->prev = trailer->prev;
		trailer->prev->next = newNode;

		newNode->next = trailer;
		trailer->prev = newNode;
		n++;
	}

	template <typename T>
	bool DoublyList<T>::removeFront() {
		if (empty()) return false;

		DNode<T>* node = header->next;

		header->next = node->next;
		node->next->prev = header;
		delete node;
		n--;
		return true;
	}

	template <typename T>
	bool DoublyList<T>::removeBack() {
		if (empty()) return false;

		DNode<T>* node = trailer->prev;
		trailer->prev = node->prev;
		node->prev->next = trailer;
		node->next = node->prev = NULL;
		delete node;
		n--;
		return true;
	}

	template <typename T>
	void DoublyList<T>::displayList() {
		if (empty()) {
			cout << "the list is empty " << endl;
		}
		else {
			DNode<T>* p = header->next;
			cout << "(" << n << ") [ ";
			while (p != trailer) {
				if (p->next == trailer) {
					cout << p->data << " ]" << endl;
				}
				else {
					cout << p->data << " , ";
				}
				p = p->next;
			}
		}
	}



	template <typename T>
	T DoublyList<T>::getBack() const {
		if (empty()) exit(1);
		return trailer->prev->data;
	}

	template <typename T>
	T DoublyList<T>::getFront() const {
		if (empty()) exit(1);
		return header->next->data;
	}

	template <typename T>
	bool DoublyList<T>::removeAll() {
		if (empty()) return false;
		while (n != 0) removeBack();
		return true;
	}

	template <typename T>
	void DoublyList<T>::insertBefore(const T& that, const T& item) {
		DNode<T>* obj = find(that);

		DNode<T>* p = header;
		while (p->next != obj) {
			p = p->next;
		}
		DNode<T>* node = createNode(item);

		node->next = p->next;
		node->prev = p;
		p->next->prev = node;
		p->next = node;
		n++;
	}

	template <typename T>
	void DoublyList<T>::insertAfter(const T& that, const T& item) {
		DNode<T>* obj = find(that);
		DNode<T>* p = header;
		while (p != obj) {
			p = p->next;
		}
		DNode<T>* node = createNode(item);

		node->next = p->next;
		node->prev = p;
		p->next->prev = node;
		p->next = node;
		n++;
	}

	template <typename T>
	bool DoublyList<T>::remove(const T& item) {
		DNode<T>* p = find(item);
		if (empty() || !p) return false;
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
		n--;
		return true;
	}

	template <typename T>
	bool DoublyList<T>::isAvailable(const T& item) const {
		if (find(item) != NULL) return true;
		else return false;
	}



	template <typename T>
	bool DoublyList<T>::swapByValues(const T& val1, const T& val2) const {
		if (!isAvailable(val1) || !isAvailable(val2)) return false;
		swapByNodes(find(val1), find(val2));
		return true;
	}


	template <typename T>
	bool DoublyList<T>::append(const DoublyList& list) const {
		if (list.empty())return false;
		DNode<T>* p = list.header->next;
		while (p != list.trailer) {
			addBack(p->data);
			p = p->next;
		}
		return true;
	}

	template <typename T>
	DoublyList<T>::~DoublyList() {
		removeAll();
		delete header;
		delete trailer;
	}

	template <typename T>
	void DoublyList<T>::printInReverse() {
		if (empty()) return;
		DNode<T>* p = trailer->prev;
		while (p != header) {
			cout << p->data << "\t";
			p = p->prev;
		}
		cout << endl;
	}

	template <typename T>
	int DoublyList<T>::count3charWord() const {
		DNode<string>* p = header->next;
		int count = 0;
		if (empty()) return 0;
		while (p != trailer) {
			if (p->data.length() == 3) count++;

			p = p->next;
		}
		return count;
	}

	template <typename T>
	bool DoublyList<T>::isPalindrome() const {
		if (empty()) return false;

		DNode<char>* last = trailer->prev;
		DNode<char>* first = header->next;
		int count = 0;

		while (last != first && count <= n / 2) {
			if (last->data != first->data)
				return false;

			count++;
			last = last->prev;
			first = first->next;
		}
		return true;
	}

	template <typename T>
	void DoublyList<T>::divide(DoublyList& obj) {
		if (!obj.empty()) obj.removeAll();
		if (empty()) exit(1);

		int count = 0;
		DNode<T>* p = header;

		while (count <= n / 2) {
			p = p->next;
			count++;
		}

		obj.header->next = p->next;
		p->next->prev = obj.header;

		obj.trailer->prev = trailer->prev;
		trailer->prev->next = obj.trailer;

		p->next = trailer;
		trailer->prev = p;

		obj.n = n - count;
		n = count;

	}

	template <typename T>
	double DoublyList<T>::sum() const {
		if (empty()) exit(1);
		double sum = 0;
		DNode<T>* p = header->next;
		while (p != trailer) {
			sum += p->data;
			p = p->next;
		}
		return sum;
	}

	template <typename T>
	double DoublyList<T>::average() const {
		return sum() / size();

	}

	template <typename T>
	T DoublyList<T>::max() const {
		if (empty()) exit(1);
		DNode<T>* p = header->next;
		T max = p->data;
		while (p != trailer) {
			if (p->data > max) max = p->data;
			p = p->next;
		}
		return max;
	}

	template <typename T>
	T DoublyList<T>::min() const {
		if (empty()) exit(1);
		DNode<T>* p = header->next;
		T min = p->data;
		while (p != trailer) {
			if (p->data < min) min = p->data;
			p = p->next;
		}
		return min;
	}

