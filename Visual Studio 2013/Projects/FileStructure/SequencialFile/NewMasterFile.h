#ifndef __NEW_MASTERFILE__
#define __NEW_MASTERFILE__

#include "Define.h"
#include "Record.h"
#include "TransactionFile.h"
//�� ������ ������ ����� ���� Ŭ����
class NewMasterFile {
private:
	//Ʈ����� ���ڵ� ����
	vector<Record> rec;
	//�� ������ ������ ����
	vector<Record> resultRec;
public:
	//Ʈ����� ������ ���޹޾� Ʈ����� ���ڵ带 �ʱ�ȭ
	NewMasterFile(TransactionFile t);
	//�� ������ ������ ����� �Լ�
	void createNewMasterFile();
	//���� Ű���� �����ϴ��� ã�� �Լ�
	Iterator findKey(int key);
	//�� ������ ������ �о� ���̴� �Լ�
	void readOldMasterFile();
	//�ϼ��� �� ������ ������ ����ϴ� �Լ�
	void printNewMasterFile();
};

#endif