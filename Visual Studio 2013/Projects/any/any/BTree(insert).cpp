#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

#define SIZE 3

class Node {
private:
	string key[SIZE - 1];
	Node* ptr[SIZE];
	Node* parent;
	int size;
public:
	friend class BTree;

	Node();
};
Node::Node() {
	for (int i = 0; i < SIZE - 1; i++)
		key[i] = "";
	memset(ptr, NULL, sizeof(Node *) * SIZE);
	parent = NULL;
	this->size = 0;
}
class BTree {
private:
	Node* root;
public:
	BTree();

	bool overflow(Node* node);
	bool leafNode(Node* node);
	Node* split(Node* node, string key);
	void inoder(Node* root);
	string middle(Node* node, string key);
	Node* search(Node* root, string key);
	void setParent(Node* node);

	void insertNode(string key);
	void insertKey(Node* node, string key, Node* left = NULL, Node* right = NULL);

	Node* getRoot();
};
BTree::BTree() {
	root = new Node();
}
bool BTree::overflow(Node* node) {
	if (node->size >= SIZE - 1)
		return true;
	return false;
}
bool BTree::leafNode(Node* node) {
	for (int i = 0; i < node->size; i++) {
		if (node->ptr[i] != NULL)
			return false;
	}
	return true;
}
Node* BTree::split(Node* node, string key) {
	int splitNum = SIZE / 2;
	int cnt = 0, i = 0;
	Node* splitNode = new Node();

	for (i = splitNum; i < SIZE - 1; i++) {
		splitNode->key[cnt] = node->key[i];
		node->key[i] = "";
		splitNode->ptr[cnt++] = node->ptr[i];
		node->size--;
		splitNode->size++;
	}
	splitNode->ptr[cnt++] = node->ptr[i];

	if (node->key[node->size - 1] > key)
		node->key[node->size - 1] = key;
	else if (splitNode->key[0] < key)
		splitNode->key[0] = key;

	return splitNode;
}
string BTree::middle(Node* node, string key) {
	string s[SIZE];

	for (int i = 0; i < node->size; i++)
		s[i] = node->key[i];
	s[SIZE - 1] = key;

	sort(s, s + SIZE);

	return s[SIZE / 2];
}
Node* BTree::search(Node* root, string key) {
	if (leafNode(root))
		return root;
	int i;
	for (i = 0; i < root->size; i++) {
		if (key < root->key[i])
			return search(root->ptr[i], key);
	}
	return search(root->ptr[i], key);
}
void BTree::setParent(Node* node) {
	for (int i = 0; i < SIZE; i++) {
		if (node->ptr[i] != NULL)
			node->ptr[i]->parent = node;
	}
}
void BTree::insertNode(string key) {
	Node* cur = search(root, key);

	if (!overflow(cur)) {
		insertKey(cur, key);
	}
	else {
		string middleKey = middle(cur, key);
		Node* splitNode = split(cur, key);

		setParent(cur);
		setParent(splitNode);

		if (cur->parent != NULL) {
			insertNode(middleKey);
		}
		else {
			Node* p = new Node();
			insertKey(p, middleKey, cur, splitNode);
			setParent(p);
			root = p;
		}
	}
}
void BTree::insertKey(Node* node, string key, Node* left, Node* right) {
	int i = node->size;

	for (i = node->size; i > 0; i--) {
		if (node->key[i - 1] > key) {
			node->key[i] = node->key[i - 1];
			node->ptr[i + 1] = node->ptr[i];
			node->key[i - 1] = "";
		}
		else {
			node->key[i] = key;
			node->ptr[i] = left;
			node->ptr[i + 1] = right;
			node->size++;
			return;
		}
	}
	node->key[i] = key;
	node->ptr[i] = left;
	node->ptr[i + 1] = right;
	node->size++;
}
void BTree::inoder(Node* root) {
	if (root == NULL)
		return;

	int i = 0;

	for (i = 0; i < root->size; i++) {
		inoder(root->ptr[i]);
		cout << root->key[i] << " ";
	}
	inoder(root->ptr[i]);
}
Node* BTree::getRoot() {
	return root;
}

int main() {
	BTree B;

	B.insertNode("b");
	B.inoder(B.getRoot());
	cout << endl;
	B.insertNode("a");
	B.inoder(B.getRoot());
	cout << endl;
	B.insertNode("c");
	B.inoder(B.getRoot());
	cout << endl;
	B.insertNode("d");
	B.inoder(B.getRoot());
	cout << endl;
	B.insertNode("f");
	B.inoder(B.getRoot());
	cout << endl;
}