#include "Record.h"

//���ڵ带 �����ϱ����� ������
Record::Record(int key, time_t time, char updateCode) {
	this->key = key;
	this->time = time;
	this->updateCode = updateCode;
}
//Ư�� ���ڵ��� ���� ������ �� �ִ� �Լ�
void Record::setKey(int key) {
	this->key = key;
}
void Record::setTime(time_t time) {
	this->time = time;
}
void Record::setUpdateCode(char updateCode) {
	this->updateCode = updateCode;
}
//Ư�� ���ڵ��� ���� ���� �� �ִ� �Լ�
int Record::getKey() {
	return key;
}
time_t Record::getTime() {
	return time;
}
char Record::getUpdateCode() {
	return updateCode;
}