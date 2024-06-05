#pragma once
#include <iostream> 
using namespace std;
//in this header file we implemented the DS 'HASH'
//ps.: we handeled collision here using 'open addressing' (we used linear probing method) 
struct bucket {
	string elem;
	bool status = false;
};

class Hash {
private : 
	bucket* hash;
	int capacity;
	int h(const string& s) { //Hashing function  :  hash code + compression method
		// hash code : maping any data type into 'int'
		//compression function : we used division method to compress the size to be in the range [0, capacity - 1]
		int size = s[0] + s[s.length() - 1];
		return size % capacity;
	}
public :
	Hash(int cap = 11) {
		hash = new bucket[cap];
		capacity = cap;
	}
	~Hash(){
		if (hash) delete[] hash;
		hash = NULL;
	}
	bool insert(const string& s) {
		int b = h(s);
		if (hash[b].status == 0) {
			hash[b].elem = s;
			hash[b].status = 1;
			return true;
		}
		for (int i = (b + 1) % capacity; i != b; i = (i + 1) % capacity)
			if (hash[i].status == 0) {
				hash[i].elem = s;
				hash[i].status = 1;
				return true;
			}
		
		return false;
	}
	int find(const string& s) {
		int b = h(s);
		if (hash[b].status == 1 && hash[b].elem == s) return b;
		for (int i = (b + 1) % capacity; i != b; i = (i + 1) % capacity)
			if (hash[i].status == 1 && hash[i].elem == s) return i;

		return -1;
	}
	bool remove(const string& s) {
		int loc = find(s);
		if (loc == -1) return false;
		hash[loc].status = 0;
		return true;
	}
};