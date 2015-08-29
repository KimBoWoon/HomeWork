#include "FileWriteException.h"

//전달받은 키값과 코드값을 예외처리 클래스에 저장한다
FileWriteException::FileWriteException(int key, char exceptionCode) {
	this->key = key;
	this->exceptionCode = exceptionCode;
}
//삽입, 수정, 삭제에 대한 예외를 처리하는 함수
//전달되는 updataCode를 받아 해당하는 예외를 출력한다
//삽입, 수정, 삭제에 대한 오류가 아닐경우 알 수 없는 오류를 출력한다
void FileWriteException::printExceptionMasseng() const {
	switch (exceptionCode) {
	case 'i':
		cout << "생성키 : " << key << " 마스터에 존재하는 레코드의 재정의" << endl;
		break;
	case 'd':
		cout << "생성키 : " << key << " 마스터에 존재하지 않는 레코드의 삭제" << endl;
		break;
	case 'm':
		cout << "생성키 : " << key << " 마스터에 존재하지 않는 레코드의 수정" << endl;
		break;
	default:
		cout << "생성키 : " << key << " 에 대한 알수없는 오류" << endl;
		break;
	}
}