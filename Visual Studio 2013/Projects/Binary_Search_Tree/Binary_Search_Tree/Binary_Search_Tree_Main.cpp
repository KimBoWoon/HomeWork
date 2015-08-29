// HW 2 : Binary Search Tree
// Name :
// Student ID :

//#include "hw2.h"
//#include "lab.hpp"
#include "Binary_Search_Tree.cpp"

int cnt = 0;

int main() {
	BinaryST<Item> bst;
	// a binary search tree of type Item

	while (1) {
		cerr << "BST > ";
		string command;
		cin >> command;

		//	cout << command << " ";
		if (command.compare("quit") == 0) {
			break;
		}
		else if (command.compare("ins") == 0) {
			int key;
			char val;
			cin >> key >> val;
			if (bst.Insert(Item(key, val)) == false)
				cout << "Key Updated" << endl;
		}
		else if (command.compare("del") == 0) {
			int key;
			cin >> key;
			if (bst.Delete(Item(key)) == false)
				cout << "Cannot Delete, Non Existing Key" << endl;
		}
		else if (command.compare("get") == 0) {
			int key;
			cin >> key;
			Item p = bst.Get(Item(key));
			if (p.key == -1)
				cout << "Non Existing Key" << endl;
			else
				cout << "Item " << p.key << " " << p.val << endl;
		}

		// show the current binary search tree
		bst.Show();
	}
	cerr << endl;

	return 1;
}