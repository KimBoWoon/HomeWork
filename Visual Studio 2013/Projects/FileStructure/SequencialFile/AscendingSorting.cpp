#include "AscendingSorting.h"
#include "Record.h"

//1���� Ű���� ������ �����ϰ�
//Ű���� ������ �ð����� ���ؼ� �������� ������ �Ѵ�
bool AscendingSorting::operator() (Record& x, Record& y) {
	if (x.getKey() == y.getKey())
		return x.getTime() < y.getTime();
	else
		return x.getKey() < y.getKey();
}