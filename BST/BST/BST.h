#pragma once
using namespace std;

template <typename T>
class Node {
	T data;
	Node<T> *parent, *left, *right;
	
	template <typename T>
	friend class BST;
};

template <typename T>
class BST {
private :
	Node<T>* root; int n;
	Node<T>* createNode(const T& data) {
		Node<T>* obj = new Node<T>;
		obj->data = data;
		obj->left = obj->right = obj->parent = NULL;
		return obj;
	}
public :
	BST(){
		root = new Node<T>;
		root = root->parent = root->left = root->right = NULL;
		n = 0;
	}

	~BST() {
		removeAll(root);
		root = NULL;
	}
	 
	void insert(const T& item) {
		Node<T>* node = createNode(item);
		
		if (!root) {
			root = node;
			n++;
			return;
		}

		Node<T>* toParent, *toNULL;
		toParent = NULL; toNULL = root;

		while (toNULL) {
			toParent = toNULL;
			if (item > toNULL->data)  toNULL = toNULL->right;
			else toNULL = toNULL->left;
		}

		if (item > toParent->data) {
			toParent->right = node;
			node->parent = toParent;
			n++;
		}
		else {
			toParent->left = node;
			node->parent = toParent;
			n++;
		}
	}
	
	void print(Node<T>* node, string type = "LNR") {
		if (!node) return;
		if (type == "LNR" || type == "ASC") {
			print(node->left, type);
			cout << node->data << "\t";
			print(node->right, type);
			return;
		}
		if (type == "RNL" || type == "DESC") {
			print(node->right, type);
			cout << node->data << "\t";
			print(node->left, type);
			return;
		}
		if (type == "LRN") {
			print(node->left, type);
			print(node->right, type);
			cout << node->data << "\t";
			return;
		}
		if (type == "RLN") {
			print(node->right, type);
			print(node->left, type);
			cout << node->data << "\t";
			return;
		}
		if (type == "NLR") {
			cout << node->data << "\t";
			print(node->left, type);
			print(node->right, type);
			return;
		}
		if (type == "NRL") {
			cout << node->data << "\t";
			print(node->right, type);
			print(node->left, type);
			return;
		}
	}

	Node<T>* find(const T& item) {
		if (!root) return NULL;
		Node<T>* copy = root;
		while (copy&& copy->data != item) {
			if (item > copy->data) copy = copy->right;
			else copy = copy->left;
		}
		return copy;
	}

	bool isRoot(const T& item) {
		if (!root) return false;
		return root == find(item);
	}

	bool isParent(const T& item) {
		if (!root) return false;
		Node<T>* isP = find(item);
		return ((isP->right != NULL) || (isP->left != NULL));
 	}

	bool isLeaf(const T& item) {
		return !isParent(item);
	}

	bool has2Children(const T& item) {
		if (!root) return false;
		Node<T>* temp = find(item);
		if (!temp) return false;
		return temp->right && temp->left;
	}

	bool hasUniChild(const T& item) {
		if (!root) return false;
		Node<T>* parent = find(item);
		return (parent->right && !parent->left) || (!parent->right && parent->left);
	}

	T getRoot() {
		if (!root) exit(1);
		return root->data;
	}

	T getParent(const T& item) {
		if (!root) exit(1);
		if (isRoot(item)) exit(1);
		Node<T>* obj = find(item);
		return obj->parent->data;
	}

	T getSibling(const T& item) {
		if (!root) exit(1);
		if (isRoot(item)) exit(1);
		Node<T>* obj = find(item);
		return (obj->parent->right == obj) ? obj->parent->left->data : obj->parent->right->data;
	}

	Node<T>* getMinFrom(Node<T>* node) {
		if (!node) exit(1);
		while (node && node->left) node = node->left;
		return node;
	}

	Node<T>* getMaxFrom(Node<T>* node) {
		if (!node) exit(1);
		while (node && node->right) node = node->right;
		return node;
	}

	Node<T>* getSuccessor(const T& item) {
		Node<T>* temp = find(item);
		if (!root || isLeaf(item)) return NULL;
		if (temp->right) {
			temp = temp->right;
			return getMinFrom(temp);
		}
		else {
			temp = temp->left;
			return getMaxFrom(temp);
		}
	}

	void removeAll(Node<T>* temp) {
		if (!temp) return;
		removeAll(temp->left);
		removeAll(temp->right);
		delete temp;
		n = 0;
	}

	T successor(const T& item) {
		return getSuccessor(item)->data;
	}

	void displayAll(string type = "LNR") {
		cout << "(" << n << ")\t[\t";
		print(root, type);
		cout << "]" << endl;
	}

	

};
