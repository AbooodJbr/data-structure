#include <iostream>
using namespace std;

template <typename T>
class SNode {
public:
	T data;
	SNode* next; // to point on the next node
};

template <typename T>
class SinglyList {
	SNode<T>* head; // to point on node that has data and next pointer
	int n; // the size of the list
public:
	SinglyList() : head(NULL), n(0) {} //constructor

	//copy constructor
	SinglyList(const SinglyList<T>& obj) {
		SNode<T>* p = obj.head;
		while (p != NULL) {
			this->addBack(p->data);
			p = p->next;
		}
	}

	//assigment operator 
	SinglyList<T>& operator=(const SinglyList<T>& obj) {
		if (this != NULL) {
			this->removeAll();
			SNode<T>* p = obj.head;
			while (p != NULL)
			{
				this->addBack(p->data);
				p = p->next;
			}
		}
	}


	bool empty() { //boolean function to check if the list is empty or not
		return head == NULL;
	}
	int size()const { return n; } // a function to return the size of the list

	void addFront(const T& item) { //this function was made to add an item to the front of the list
		SNode<T>* m = new SNode<T>; //first we allocate a new node to put the item on it
		m->data = item;
		m->next = NULL;

		// then here check if the list is empty
		//if its empty we add the new node to the head directly
		if (empty()) {
			head = m;
			n++;
			return; //the return is only to close the function
		}
		// else if its not empty we make the next pointer point to the head 
		// and make the head point to the new node
		else {
			m->next = head;
			head = m;
			n++;
			return;
		}
	}

	//this function is made to return the first element/item in the list
	T getFront() const {
		if (empty()) exit(1); //if the list is empty close the program
		return head->data;
	}

	//this function is made to display all elements in the list
	void displayList() const {
		if (n == 0) cout << "the list is empty" << endl;
		SNode<T>* p = head; //first we make a temporary object = head
		//as long as the p is not null print the data 
		while (p) {
			cout << p->data << ", ";
			p = p->next; //this is like p++ in arrays
		}
		cout << endl;
	}

	//this function is made to return the last element in the list
	T getBack()const {
		//first we check if its empty we exit the program
		if (empty()) exit(1);
		//if its not empty we make a new node = head
		SNode <T>* p = head;
		//as long as p and p->next is not null keep moving to the next node
		while (p && p->next) { p = p->next; } //this is how we get to the last element
		return p->data;
	}

	//this function is made to remove the first element
	bool removeFront() {
		//first as usual we check if the list is empty
		if (empty()) return false;

		//now we make a new pointer that points to the head
		SNode<T>* old = head;
		//and the head points on the next element
		head = head->next;
		//now we remove the "OLD" to remove it from the list by making the next point to null and delete it
		old->next = NULL;
		delete old;
		n--;
		return true;
	}

	~SinglyList() {
		while (!empty())
			removeFront();
		head = NULL;
		n = 0;
	}

	//this function is made to add to the back of the list
	void addBack(const T item) {
		//first we allocate a new node to put the new data in it
		SNode <T>* m = new SNode<T>;
		m->next = NULL;
		m->data = item;

		//if the list is empty we add it to the head
		if (empty()) {
			head = m;
			n++;
			return;
		}
		//if its not empty
		else {
			//we make a new pointer that points to the head 
			//and use it as a counter to reach the last node
			SNode<T>* p = head;
			while (p && p->next) { p = p->next; }
			//after reaching the last node we make the next pointer point to new node
			p->next = m;
			n++;
		}
	}
	bool removeBack() {
		if (empty()) {
			return false;
		}
		SNode<T>* last, * b4;
		last = b4 = head;
		while (last && last->next) {
			b4 = last;
			last = last->next;
		}
		delete last;
		b4->next = NULL;
		n--;
		return true;
	}

	//find and return node 
	SNode<T>* find(const T& item) {
		if (empty()) return NULL;

		SNode<T>* p = head;
		while (p && p->data != item)
			p = p->next;
		return p;
	}

	bool remove(const T& item) {
		SNode<T>* p = find(item);
		if (!p) return false;

		if (p == head) removeFront();
		else if (p->next == NULL) removeBack();
		else {
			removeBefore(p->next);
			SNode<T>* q = head;
			while (q->next != p) q = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
			n--;
		}
		return true;
	}

	void swapNodes(SNode<T>* n1, SNode<T>* n2) {
		SNode<T>* p1 = n2->next;
		SNode<T>* p2 = head;
		while (p2->next != n1) p2 = p2->next;
		if (head == n1) {
			head = n2;
		}
		else{ p2->next = n2; }
		n2->next = n1->next;
		n1->next = p1;
	}

	void append(const SinglyList<T>& obj) {
		SNode<T>* p = head->next;
		while (p != NULL) {
			addBack(p->data);
		}
	}

	bool removeAll() {
		if (empty()) return false;

		while (n != 0) removeBack();
		head = NULL;
		return true;
	}

	void insertBefore(SNode<T>* obj, const T& item) {
		SNode<T>* p = head;
		SNode<T>* m = new SNode<T>;
		m->data = item;
		m->next = obj;
		if (obj == head) {
			addFront(item);
		}
		else
		{
			while (p && p->next != obj) {
				p = p->next;
			}
			p->next = m;
			n++;
		}
	}
	void insertAfter(SNode<T>* obj, const T& item) {
		SNode<T>* m = new SNode<T>;
		m->data = item;
		SNode<T>* p = obj->next;
		obj->next = m;
		m->next = p;
		n++;
	}
	bool removeBefore(SNode<T>* obj) {
		if (empty()) return false;
		if (obj == head) return false;
		SNode<T>* p = head;
		while (p && p->next->next != obj) {
			p = p->next;
		}
		SNode<T>* old = p->next;
		p->next = old->next;
		delete old;
		n--;
		return true;
	}
	bool removeAfter(SNode<T>* obj) {
		if (empty()) return false;
		SNode<T>* p = obj->next;
		obj->next = obj->next->next;
		delete p;
		n--;
		return true;
	}

};

int main() {
	SinglyList<int> list;
	list.addFront(10);
	list.addFront(20);
	list.addBack(5);
	SNode<int>* ptr = list.find(20);
	list.insertAfter(ptr, 11);
	list.displayList();
	list.removeBefore(ptr);
	list.insertBefore(ptr, 6);
	list.displayList();
	cout << list.size() << endl;

}