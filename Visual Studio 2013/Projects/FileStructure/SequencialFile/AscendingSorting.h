#ifndef __ASCENDING__
#define __ASCENDING__

#include "Define.h"
//�������� ������ �ϱ����� Functor
class AscendingSorting {
public:
	bool operator() (Record& x, Record& y);
};

#endif