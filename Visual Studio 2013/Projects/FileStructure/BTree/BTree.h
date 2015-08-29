#ifndef __B_TREE__
#define __B_TREE__

#include "Define.h"
#include "Node.h"

class BTree {
private:
	Node* root;
public:
	//��Ʈ��� ����
	BTree();
	//��� ����
	Node* insertNode(Node* node, string key, Node* left, Node* right);
	//Ʈ�� ��ȸ
	void inorder(Node* root);
	//��忡 Ű�� �� �� �ִ��� Ȯ��
	bool overflow(Node* cur);
	//��带 ������ ������ ��带 ��ȯ
	Node* split(Node* node);
	//�߰� Ű���� ���Ѵ�
	string middle(Node* node, string key);
	//�ڽ��� ����������� Ȯ���Ѵ�
	bool leafNode(Node* root);
	//Ű���� �� ��带 ã�´�
	Node* search(Node* root, string key);
	//����� �θ��� �����Ѵ�
	void setParent(Node* node);
	//��忡 Ű���� ����
	void insertKey(Node* node, string key, Node* left, Node* right);
	//��� ����
	void deleteNode(Node* root, string key = "");
	//��忡�� Ű���� ����
	void deleteKey(Node* node, string key);
	//���� ��� Ȯ��
	int sibling(Node* node);
	//�� �� �ּҰ��� �ִ��� Ȯ��
	int findIndex(Node* node, string key = "");
	//Ű���� �� ��°�� ��ġ�ϴ��� ã�´�
	int findKey(Node* node, string key);
	//Ű���� ��� ��忡 �ִ��� ã�´�
	Node* keySearch(Node* root, string key);
	//����÷ο� Ȯ��
	bool underflow(Node* node);
	//��й�
	void redistribution(Node* node, int nodeIndex, int siblingIndex);
	//��带 ��ģ��
	void mergeNode(Node* node, int nodeIndex);
	//��带 �湮�ؼ� �ؾ�����
	void visitNode(Node* node, int nodeNum);
	//Ʈ���� ����
	int height(Node* root);
	//��Ʈ�� ��ȯ
	Node* getRoot();
	//��Ʈ�� ����
	void setRoot(Node* root);
};

#endif