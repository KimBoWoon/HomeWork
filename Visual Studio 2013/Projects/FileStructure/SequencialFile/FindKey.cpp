#include "FindKey.h"

//같은 키값이 존재할경우 참을 반환
bool FindKey::operator() (Record& r) {
	return r.getKey() == key;
}