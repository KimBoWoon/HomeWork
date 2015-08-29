#include "TransactionFile.h"
#include "NewMasterFile.h"

int main() {
	//Ʈ����� ������ ��������� �ν��Ͻ� ����
	TransactionFile transactionFile;

	//Ʈ����� ������ ����
	transactionFile.createTransactionFile();

	//������� Ʈ����� ������ ���
	cout << "��� 1(Create Log File)" << endl;
	transactionFile.printTransactionFile();

	//Ʈ����� ������ �����ѵ� �ٽ� �ѹ� ���
	cout << "��� 2(Sorting)" << endl;
	transactionFile.sortingTransactionFile();
	transactionFile.printTransactionFile();

	//�� ������ ������ ��������� �ν��Ͻ� ����
	NewMasterFile newMasterFile(transactionFile);

	//�� ������ ���ϰ� Ʈ����� ������ �������
	//�� ������ ������ �����ϰ� ����Ѵ�
	newMasterFile.createNewMasterFile();
	cout << "��� 3(New Master File)" << endl;
	newMasterFile.printNewMasterFile();
}