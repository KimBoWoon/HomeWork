#ifndef __RECORD__
#define __RECORD__

#include "Define.h"
//Ʈ����� ���Ͽ� ����Ǵ� �ϳ��� ���ڵ带 ��Ÿ���� Ŭ����
class Record {
private:
	int key;	//���ڵ��� Ű��
	time_t time;	//���� �߰��Ǿ����� �˼��ִ� �ð���
	char updateCode;	//����, ����, ������ ���� �ڵ尪
public:
	//�ϳ��� ���ڵ� ������ ����� ������
	//���� ���ڰ� ������ Key = 0, Time = 0, updataCode = 0���� �ʱ�ȭ �ȴ�
	Record(int key = 0, time_t time = 0, char updateCode = 0);
	//���ڵ��� Ư������ �����ų���ִ� �Լ�
	void setKey(int key);
	void setTime(time_t time);
	void setUpdateCode(char updateCode);
	//���ڵ��� Ư������ �����ִ� �Լ�
	int getKey();
	time_t getTime();
	char getUpdateCode();
};

#endif