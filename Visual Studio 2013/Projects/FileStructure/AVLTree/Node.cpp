#include "Node.h"

Node::Node(string key, Node* left, Node* right) {
	this->key = key;
	this->left = left;
	this->right = right;
}