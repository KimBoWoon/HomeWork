#include "TransactionFile.h"
#include "Record.h"
#include "AscendingSorting.h"

//Ʈ����� ������ ����
void TransactionFile::createTransactionFile() {
	const char code[3] = { 'i', 'm', 'd' };

	//������ ������� �õ尪 �ο�
	srand((unsigned int) time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		Record r;

		//���ڵ��� Ű���� �����ϰ� ����
		r.setKey((rand() % 20) + 1);
		//������ ������ �ð��� ���ڵ� ���� �ð��̶�� ����
		r.setTime(time(NULL));
		//updataCode����
		r.setUpdateCode(code[rand() % 3]);
		//���� �ð����� ��µǼ� �����̸� �ɾ��ش�
		Sleep(1000);

		rec.push_back(r);
	}
}
void TransactionFile::sortingTransactionFile() {
	AscendingSorting ascending;

	//�ϼ��� Ʈ����� ������ ����
	sort(rec.begin(), rec.end(), ascending);
}
void TransactionFile::printTransactionFile() {
	//�ϼ��� Ʈ����� ������ ���
	for (Iterator iter = rec.begin(); iter < rec.end(); iter++)
		cout << "Key : " << (*iter).getKey() << ", Time : " << (*iter).getTime() << ", UpdateCode : " << (*iter).getUpdateCode() << endl;
}
vector<Record> TransactionFile::getRecordVector() {
	//Ʈ����� ������ ��ȯ
	return rec;
}