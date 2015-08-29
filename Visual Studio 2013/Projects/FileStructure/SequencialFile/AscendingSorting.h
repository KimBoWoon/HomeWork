#ifndef __ASCENDING__
#define __ASCENDING__

#include "Define.h"
//오름차순 정렬을 하기위한 Functor
class AscendingSorting {
public:
	bool operator() (Record& x, Record& y);
};

#endif