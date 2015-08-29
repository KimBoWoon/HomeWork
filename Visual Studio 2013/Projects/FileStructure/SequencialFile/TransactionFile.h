#ifndef __TRANSACTION_FILE__
#define __TRANSACTION_FILE__

#include "Define.h"
#include "Record.h"
//���� ���ڵ���� �� ������� Ʈ����� ����
class TransactionFile {
private:
	//Ʈ����� ������ ����Ǵ� ����
	vector<Record> rec;
public:
	//Ʈ����� ������ ����� �Լ�
	void createTransactionFile();
	//Ʈ����� ������ Ű���� �ð������� �����ϴ� �Լ�
	void sortingTransactionFile();
	//�ϼ��� Ʈ����� ������ ����ϴ� �Լ�
	void printTransactionFile();

	//�� ������ ���Ͽ� �����ϱ� ���� Ʈ����� ������ �Ѱ��ִ� �Լ�
	vector<Record> getRecordVector();
};

#endif