#ifndef __NODE__
#define __NODE__

#include "Define.h"
//노드를 나타내는 클래스
class Node {
private:
	string key;
	Node* left, *right;
public:
	//BST는 자유롭게 노드에 접근할 수 있다
	friend class AVLTree;

	Node(string key, Node* left = NULL, Node* right = NULL);
};

#endif