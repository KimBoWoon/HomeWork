#ifndef __NEW_MASTERFILE__
#define __NEW_MASTERFILE__

#include "Define.h"
#include "Record.h"
#include "TransactionFile.h"
//신 마스터 파일을 만들기 위한 클래스
class NewMasterFile {
private:
	//트랜잭션 레코드 파일
	vector<Record> rec;
	//신 마스터 파일을 저장
	vector<Record> resultRec;
public:
	//트랜잭션 파일을 전달받아 트랜잭션 레코드를 초기화
	NewMasterFile(TransactionFile t);
	//신 마스터 파일을 만드는 함수
	void createNewMasterFile();
	//같은 키값이 존재하는지 찾는 함수
	Iterator findKey(int key);
	//구 마스터 파일을 읽어 들이는 함수
	void readOldMasterFile();
	//완성된 신 마스터 파일을 출력하는 함수
	void printNewMasterFile();
};

#endif