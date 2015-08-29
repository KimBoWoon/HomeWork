#ifndef __RECORD__
#define __RECORD__

#include "Define.h"
//트랜잭션 파일에 저장되는 하나의 레코드를 나타내는 클래스
class Record {
private:
	int key;	//레코드의 키값
	time_t time;	//언제 추가되었는지 알수있는 시간값
	char updateCode;	//삽입, 수정, 삭제를 위한 코드값
public:
	//하나의 레코드 파일을 만드는 생성자
	//전달 인자가 없으면 Key = 0, Time = 0, updataCode = 0으로 초기화 된다
	Record(int key = 0, time_t time = 0, char updateCode = 0);
	//레코드의 특정값을 변경시킬수있는 함수
	void setKey(int key);
	void setTime(time_t time);
	void setUpdateCode(char updateCode);
	//레코드의 특정값을 얻어낼수있는 함수
	int getKey();
	time_t getTime();
	char getUpdateCode();
};

#endif