#ifndef __FIND_KEY__
#define __FIND_KEY__

#include "Define.h"
#include "Record.h"
//������ �ִ� Ű���� ���ؼ� ���� Ű���� �ִ��� ã������ Functor
class FindKey {
public:
	int key;
	bool operator() (Record& r);
};

#endif