#ifndef __NODE__
#define __NODE__

#include "Define.h"

class Node {
private:
	string key[SIZE - 1];
	Node* ptr[SIZE];
	Node* parent;
	int keyCount;
public:
	//BTree Ŭ������ NodeŬ������ ��������� �ٷ���ִ�
	friend class BTree;
	//��� ����
	Node();
};

#endif