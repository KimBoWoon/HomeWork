#ifndef __NODE__
#define __NODE__

#include "Define.h"
//��带 ��Ÿ���� Ŭ����
class Node {
private:
	string key;
	Node* left, *right;
public:
	//BST�� �����Ӱ� ��忡 ������ �� �ִ�
	friend class AVLTree;

	Node(string key, Node* left = NULL, Node* right = NULL);
};

#endif