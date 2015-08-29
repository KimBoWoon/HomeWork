/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include <curses.h>//pdcurses 헤더파일
#include <iostream>
#include <fstream>
#include <ctime>	//랜드함수의 시드값을 주기위해 포함
using namespace std;

#define height 20	//게임 표현화면의 높이
#define width 11	//게임 표현화면의 넓이

class KeySet//키값에 관한 클래스
{
private:
	int key;
public:
	int input_key();//키값을 받아오는 함수
};