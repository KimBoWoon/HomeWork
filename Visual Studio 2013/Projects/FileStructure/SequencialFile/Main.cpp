#include "TransactionFile.h"
#include "NewMasterFile.h"

int main() {
	//트랜잭션 파일을 만들기위해 인스턴스 생성
	TransactionFile transactionFile;

	//트랜잭션 파일을 생성
	transactionFile.createTransactionFile();

	//만들어진 트랜잭션 파일을 출력
	cout << "출력 1(Create Log File)" << endl;
	transactionFile.printTransactionFile();

	//트랜잭션 파일을 정렬한뒤 다시 한번 출력
	cout << "출력 2(Sorting)" << endl;
	transactionFile.sortingTransactionFile();
	transactionFile.printTransactionFile();

	//신 마스터 파일을 만들기위해 인스턴스 생성
	NewMasterFile newMasterFile(transactionFile);

	//구 마스터 파일과 트랜잭션 파일을 기반으로
	//신 마스터 파일을 생성하고 출력한다
	newMasterFile.createNewMasterFile();
	cout << "출력 3(New Master File)" << endl;
	newMasterFile.printNewMasterFile();
}