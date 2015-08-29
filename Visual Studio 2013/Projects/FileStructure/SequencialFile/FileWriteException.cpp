#include "FileWriteException.h"

//���޹��� Ű���� �ڵ尪�� ����ó�� Ŭ������ �����Ѵ�
FileWriteException::FileWriteException(int key, char exceptionCode) {
	this->key = key;
	this->exceptionCode = exceptionCode;
}
//����, ����, ������ ���� ���ܸ� ó���ϴ� �Լ�
//���޵Ǵ� updataCode�� �޾� �ش��ϴ� ���ܸ� ����Ѵ�
//����, ����, ������ ���� ������ �ƴҰ�� �� �� ���� ������ ����Ѵ�
void FileWriteException::printExceptionMasseng() const {
	switch (exceptionCode) {
	case 'i':
		cout << "����Ű : " << key << " �����Ϳ� �����ϴ� ���ڵ��� ������" << endl;
		break;
	case 'd':
		cout << "����Ű : " << key << " �����Ϳ� �������� �ʴ� ���ڵ��� ����" << endl;
		break;
	case 'm':
		cout << "����Ű : " << key << " �����Ϳ� �������� �ʴ� ���ڵ��� ����" << endl;
		break;
	default:
		cout << "����Ű : " << key << " �� ���� �˼����� ����" << endl;
		break;
	}
}