#ifndef __FILE_WRITE_EXCEPTION__
#define __FILE_WRITE_EXCEPTION__

#include "Define.h"
//삽입, 수정, 삭제에 대한 예외를 출력하기위한 예외처리 클래스
class FileWriteException {
private:
	int key;
	char exceptionCode;
public:
	FileWriteException(int key = 0, char exceptionCode = 0);
	void printExceptionMasseng() const;
};

#endif