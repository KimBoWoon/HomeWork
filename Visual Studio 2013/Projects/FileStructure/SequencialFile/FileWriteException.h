#ifndef __FILE_WRITE_EXCEPTION__
#define __FILE_WRITE_EXCEPTION__

#include "Define.h"
//����, ����, ������ ���� ���ܸ� ����ϱ����� ����ó�� Ŭ����
class FileWriteException {
private:
	int key;
	char exceptionCode;
public:
	FileWriteException(int key = 0, char exceptionCode = 0);
	void printExceptionMasseng() const;
};

#endif