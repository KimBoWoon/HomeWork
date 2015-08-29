#ifndef __TRANSACTION_FILE__
#define __TRANSACTION_FILE__

#include "Define.h"
#include "Record.h"
//여러 레코드들이 모여 만들어진 트랜잭션 파일
class TransactionFile {
private:
	//트랜잭션 파일이 저장되는 변수
	vector<Record> rec;
public:
	//트랜잭션 파일을 만드는 함수
	void createTransactionFile();
	//트랜잭션 파일을 키값과 시간값으로 정렬하는 함수
	void sortingTransactionFile();
	//완성된 트랜잭션 파일을 출력하는 함수
	void printTransactionFile();

	//신 마스터 파일에 전달하기 위해 트랜잭션 파일을 넘겨주는 함수
	vector<Record> getRecordVector();
};

#endif