#ifndef __BINARY_SERACH_TREE__
#define __BINARY_SERACH_TREE__

#include "Define.h"
#include "Node.h"

class AVLTree{
private:
	//BST�� ��Ʈ
	Node* root;
public:
	AVLTree();
	//����� ����
	void insertNode(string key);
	//����� ����
	void deleteNode(string key);
	//��� �˻�
	Node** serachNode(string key, Node* returnPoint[2]);

	//Ʈ�� ��ȸ
	void inorder(Node* root);

	//��Ʈ�� ����
	Node* getRoot();
	//��� �湮
	void visitNode(Node* root);
	//Ʈ���� ����
	int height(Node* root);
	//����� ����
	int nodeCount(Node* root);
	//Ű���� ���� ū ���
	string maxNode(Node* root);
	//Ű���� ���� ���� ���
	string minNode(Node* root);

	int getHeightDiff(Node* rebalanceNode);
	void rebalance(Node** root);
	void LL(Node** root);
	void RR(Node** root);
	void LR(Node** root);
	void RL(Node** root);
};

#endif