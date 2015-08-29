#include "AscendingSorting.h"
#include "Record.h"

//1차로 키값을 가지고 정렬하고
//키값이 같으면 시간값을 비교해서 오름차순 정렬을 한다
bool AscendingSorting::operator() (Record& x, Record& y) {
	if (x.getKey() == y.getKey())
		return x.getTime() < y.getTime();
	else
		return x.getKey() < y.getKey();
}