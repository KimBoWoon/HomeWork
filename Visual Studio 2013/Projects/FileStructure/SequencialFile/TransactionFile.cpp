#include "TransactionFile.h"
#include "Record.h"
#include "AscendingSorting.h"

//트랜잭션 파일을 생성
void TransactionFile::createTransactionFile() {
	const char code[3] = { 'i', 'm', 'd' };

	//난수를 얻기위해 시드값 부여
	srand((unsigned int) time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		Record r;

		//레코드의 키값을 랜덤하게 지정
		r.setKey((rand() % 20) + 1);
		//난수가 생성된 시간을 레코드 생성 시간이라고 간주
		r.setTime(time(NULL));
		//updataCode설정
		r.setUpdateCode(code[rand() % 3]);
		//같은 시간값이 출력되서 딜레이를 걸어준다
		Sleep(1000);

		rec.push_back(r);
	}
}
void TransactionFile::sortingTransactionFile() {
	AscendingSorting ascending;

	//완성된 트랜잭션 파일을 정렬
	sort(rec.begin(), rec.end(), ascending);
}
void TransactionFile::printTransactionFile() {
	//완성된 트랜잭션 파일을 출력
	for (Iterator iter = rec.begin(); iter < rec.end(); iter++)
		cout << "Key : " << (*iter).getKey() << ", Time : " << (*iter).getTime() << ", UpdateCode : " << (*iter).getUpdateCode() << endl;
}
vector<Record> TransactionFile::getRecordVector() {
	//트랜잭션 파일을 반환
	return rec;
}