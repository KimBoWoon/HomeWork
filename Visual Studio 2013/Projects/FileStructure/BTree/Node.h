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
	//BTree 클래스는 Node클래스를 자유자재로 다룰수있다
	friend class BTree;
	//노드 생성
	Node();
};

#endif