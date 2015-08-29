#ifndef __BINARY_SERACH_TREE__
#define __BINARY_SERACH_TREE__

#include "Define.h"
#include "Node.h"

class BinarySerachTree {
private:
	//BST의 루트
	Node* root;
public:
	BinarySerachTree();
	//노드의 삽입
	void insertNode(string key);
	//노드의 제거
	void deleteNode(string key);
	//노드 검색
	Node** serachNode(string key, Node* returnPoint[2]);

	//트리 순회
	void inorder(Node* root);

	//루트값 참조
	Node* getRoot();
	//노드 방문
	void visitNode(Node* root);
	//트리의 높이
	int height(Node* root);
	//노드의 갯수
	int nodeCount(Node* root);
	//키값이 가장 큰 노드
	string maxNode(Node* root);
	//키값이 가장 작은 노드
	string minNode(Node* root);
};

#endif