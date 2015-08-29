#include "Record.h"

//레코드를 정의하기위한 생성자
Record::Record(int key, time_t time, char updateCode) {
	this->key = key;
	this->time = time;
	this->updateCode = updateCode;
}
//특정 레코드의 값을 변경할 수 있는 함수
void Record::setKey(int key) {
	this->key = key;
}
void Record::setTime(time_t time) {
	this->time = time;
}
void Record::setUpdateCode(char updateCode) {
	this->updateCode = updateCode;
}
//특정 레코드의 값을 얻을 수 있는 함수
int Record::getKey() {
	return key;
}
time_t Record::getTime() {
	return time;
}
char Record::getUpdateCode() {
	return updateCode;
}