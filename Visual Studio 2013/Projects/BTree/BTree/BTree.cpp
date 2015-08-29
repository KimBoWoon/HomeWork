#include <iostream>
#include <memory>
#include <stack>
#include <algorithm>
using namespace std;

#define SIZE 3

class Node {
private:
	int key[SIZE - 1];
	Node* ptr[SIZE];
	Node* parent;
	int size;
public:
	friend class BTree;
	Node();
};
Node::Node() : size(0) {
	memset(key, 0, sizeof(int) * SIZE - 1);
	memset(ptr, NULL, sizeof(Node*) * SIZE);
	parent = NULL;
}
class BTree {
private:
	Node* root;
public:
	BTree();

	bool overflow(Node* node);
	Node* search(Node* node, int key);
	bool leafNode(Node* node);
	void inorder(Node* root);
	void visitNode(Node* node, int nodeNum);
	void setParent(Node* node);
	Node* split(Node* node);
	int middle(Node* node, int key);

	void insertNode(int key, Node* node = NULL, Node* left = NULL, Node* right = NULL);
	void insertKey(Node* node, int key, Node* left = NULL, Node* right = NULL);

	Node* getRoot();
};
BTree::BTree() {
	root = new Node;
}
bool BTree::overflow(Node* node) {
	if (node->size >= SIZE - 1)
		return true;
	else
		return false;
}
Node* BTree::search(Node* node, int key) {
	if (node != NULL) {
		if (leafNode(node))
			return node;
		int i;
		for (i = 0; i < node->size + 1; i++) {
			if (key < node->key[i])
				return search(node->ptr[i], key);
		}
		return search(node->ptr[i], key);
	}
}
void BTree::inorder(Node* root) {
	if (root == NULL)
		return;
	else {
		int i;
		for (i = 0; i < root->size; i++) {
			inorder(root->ptr[i]);
			visitNode(root, i);
		}
		inorder(root->ptr[i]);
	}
}
void BTree::visitNode(Node* node, int nodeNum) {
	cout << node->key[nodeNum] << " ";
}
bool BTree::leafNode(Node* node) {
	for (int i = 0; i < SIZE; i++) {
		if (node->ptr[i] != NULL)
			return false;
	}
	return true;
}
void BTree::setParent(Node* node) {
	for (int i = 0; i < node->size + 1; i++) {
		if (node->ptr[i] != NULL)
			node->ptr[i]->parent = node;
	}
}
Node* BTree::split(Node* node) {
	Node* p = new Node;
	int i = 0, size = node->size;

	for (int j = SIZE / 2; j < size; j++) {
		p->key[i] = node->key[j];
		node->key[j] = 0;
		p->ptr[i] = node->ptr[j];
		i++;
		p->size++;
		node->size--;
	}
	return p;
}
int BTree::middle(Node* node, int key) {
	int arr[SIZE] = { 0 };

	for (int i = 0; i < node->size; i++)
		arr[i] = node->key[i];
	arr[SIZE - 1] = key;

	sort(arr, arr + SIZE - 1, less<int>());

	return arr[SIZE / 2];
}
void BTree::insertNode(int key, Node* node, Node* left, Node* right) {
	//Node* cur = search(root, key);
	Node* cur = root;
	stack<Node*> s;
	int i = 0, n = 0;

	do {
		n = cur->size;
		i = 0;
		while (i < n && key > cur->key[i])
			i++;
		if (leafNode(cur))
			break;
		else {
			s.push(cur);
			cur = cur->ptr[i];
		}
	} while (cur != NULL);

	bool finish = false;
	Node* temp = cur;

	do {
		if (!overflow(temp)) {
			insertKey(temp, key);
			finish = true;
		}
		else {
			int middleKey = middle(cur, key);
			Node* splitNode = split(cur);
			if (cur->key[cur->size - 1] > key) {
				int temp = cur->key[cur->size - 1];
				cur->key[cur->size - 1] = key;
				key = temp;
			}
			else if (splitNode->key[0] < key) {
				int temp = splitNode->key[0];
				splitNode->key[0] = key;
				key = temp;
			}

			if (!s.empty()) {
				temp = s.top();
				if (!overflow(temp)) {
					insertKey(temp, middleKey, cur, splitNode);
					finish = true;
				}
				s.pop();
			}
			else {
				Node* newRoot = new Node;
				insertKey(newRoot, middleKey, cur, splitNode);
				root = newRoot;
				finish = true;
			}
		}
	} while (!finish);
}
void BTree::insertKey(Node* node, int key, Node* left, Node* right) {
	int i;

	for (i = node->size; i > 0; i--) {
		if (key > node->key[i - 1]) {
			node->key[i] = key;
			node->ptr[i] = left;
			node->ptr[i + 1] = right;
			node->size++;
			return;
		}
		else {
			node->key[i] = node->key[i - 1];
			node->ptr[i + 1] = node->ptr[i];
		}
	}
	node->key[i] = key;
	node->ptr[i] = left;
	node->ptr[i + 1] = right;
	node->size++;
}
Node* BTree::getRoot() {
	return root;
}
int main() {
	BTree B;

	B.insertNode(3);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(1);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(4);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(5);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(6);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(7);
	B.inorder(B.getRoot());
	cout << endl;
	B.insertNode(8);
	B.inorder(B.getRoot());
	cout << endl;

	return 0;
}