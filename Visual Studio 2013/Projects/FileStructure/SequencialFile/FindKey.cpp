#include "FindKey.h"

//���� Ű���� �����Ұ�� ���� ��ȯ
bool FindKey::operator() (Record& r) {
	return r.getKey() == key;
}