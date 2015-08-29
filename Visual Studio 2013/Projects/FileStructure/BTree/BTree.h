#ifndef __B_TREE__
#define __B_TREE__

#include "Define.h"
#include "Node.h"

class BTree {
private:
	Node* root;
public:
	//루트노드 생성
	BTree();
	//노드 삽입
	Node* insertNode(Node* node, string key, Node* left, Node* right);
	//트리 순회
	void inorder(Node* root);
	//노드에 키가 들어갈 수 있는지 확인
	bool overflow(Node* cur);
	//노드를 나눠서 나눠진 노드를 반환
	Node* split(Node* node);
	//중간 키값을 구한다
	string middle(Node* node, string key);
	//자신이 리프노드인지 확인한다
	bool leafNode(Node* root);
	//키값이 들어갈 노드를 찾는다
	Node* search(Node* root, string key);
	//노드의 부모값을 설정한다
	void setParent(Node* node);
	//노드에 키값을 삽입
	void insertKey(Node* node, string key, Node* left, Node* right);
	//노드 제거
	void deleteNode(Node* root, string key = "");
	//노드에서 키값을 제거
	void deleteKey(Node* node, string key);
	//형제 노드 확인
	int sibling(Node* node);
	//몇 번 주소값에 있는지 확인
	int findIndex(Node* node, string key = "");
	//키값이 몇 번째에 위치하는지 찾는다
	int findKey(Node* node, string key);
	//키값이 어느 노드에 있는지 찾는다
	Node* keySearch(Node* root, string key);
	//언더플로우 확인
	bool underflow(Node* node);
	//재분배
	void redistribution(Node* node, int nodeIndex, int siblingIndex);
	//노드를 합친다
	void mergeNode(Node* node, int nodeIndex);
	//노드를 방문해서 해야할일
	void visitNode(Node* node, int nodeNum);
	//트리의 높이
	int height(Node* root);
	//루트값 반환
	Node* getRoot();
	//루트값 설정
	void setRoot(Node* root);
};

#endif