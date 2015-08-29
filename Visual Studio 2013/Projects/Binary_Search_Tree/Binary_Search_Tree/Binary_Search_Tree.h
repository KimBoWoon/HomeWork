// HW 2 : Binary Search Tree
// Name :
// Student ID :

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include<iostream>
#include<string>
using namespace std;

// Item Class
// this is the key-value pair
// We are going to put this pair into each node of the BinaryST
struct Item {
	int key;
	char val;
	Item(int k, int v = 0) { key = k; val = v; };
	Item() {};
};

// forward declaration
template <class T> class BinaryST;

// ---------- BSTNode class -------------
// This is the class for each node of the binary search tree

template <class T>
class BSTNode {
	friend class BinaryST < T > ;

private:
	T data;	// storage for data : in HW 3, T will be Item
	BSTNode<T> *lC;	// link to the left Child
	BSTNode<T> *rC;	// link to the right Child

public:
	// constructors come here
	BSTNode(T d);
};

template <class T>
BSTNode<T>::BSTNode(T d) {
	// data is given
	data = d;

	// the lC and rC field are NULL
	lC = rC = NULL;
}

// ---------- BinaryST class -------------
template <class T>
class BinaryST {
public:
	BinaryST();	// constructor
	~BinaryST(); // destructor

	bool  Insert(T keyval);
	T  Get(T keyval);
	bool  Delete(T keyval);

	void  PreOrder(BSTNode<T> *ptr);
	void  InOrder(BSTNode<T> *ptr);
	void  PostOrder(BSTNode<T> *ptr);
	int  Count(BSTNode<T> *ptr);
	int  Height(BSTNode<T> *ptr);


	void  Show();	// Show the nodes in the Binary Search Tree  
private:
	BSTNode<T>* root; // pointer to the root node
};

template<class T>
BinaryST<T>::BinaryST() {
	// BinaryST constructor. Initialize root variable
	root = NULL; // root is NULL, an empty binary search tree
}


template<class T>
BinaryST<T>::~BinaryST()
{ // BinaryST destructor. Delete all nodes 
	// in the binary search tree

	// ignore this in HW 3

}


template <class T>
void  BinaryST<T>::Show()  {
	cout << "Pre  Order : ";
	PreOrder(root);
	cout << endl << "In   Order : ";
	InOrder(root);
	cout << endl << "Post Order : ";
	PostOrder(root);
	cout << endl << "Count      : ";
	cout << Count(root);
	cout << endl << "Height      : ";
	cout << Height(root) << endl << endl;
}

#endif