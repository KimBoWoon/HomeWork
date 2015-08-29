#ifndef __FIND_KEY__
#define __FIND_KEY__

#include "Define.h"
#include "Record.h"
//가지고 있는 키값과 비교해서 같은 키값이 있는지 찾기위한 Functor
class FindKey {
public:
	int key;
	bool operator() (Record& r);
};

#endif