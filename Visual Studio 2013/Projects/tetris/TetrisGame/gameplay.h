#ifndef __GAMEPLAY__
#define __GAMEPLAY__

#include <curses.h>//pdcurses 헤더파일
#include <iostream>
#include <fstream>
#include <ctime>	//랜드함수의 시드값을 주기위해 포함
using namespace std;

#define height 20	//게임 표현화면의 높이
#define width 11	//게임 표현화면의 넓이

class GamePlay//게임 플레이에 관한 클래스
{
protected:
	int x, y, cnt, score, randomnumber, state, random;//x, y좌표값, 클리어를 위한 변수, 점수를 나타내는 변수, 블럭을 만들어내기 위한 변수, 회전하기위한 변수 선언
	int hold[20][20];//좌표값을 2차원배열에 저장
public:
	bool gameplay(WINDOW *win1, WINDOW *win2, char cur_key);//게임 플레이를 표현해주는 함수
	int GetX();	//다른 함수에서 x값을 참조하기위해 Get함수를 선언
	int GetY();	//다른 함수에서 y값을 참조하기위해 Get함수를 선언
	void Setrandomnumber(int n);//랜덤넘버를 초기화해주는 함수
	void lineclaer(WINDOW* win1, WINDOW* win2);	//줄을 없애기 위한 함수
	void display(WINDOW* win1, int x, int y);	//화면에 나타내기 위한 함수
	GamePlay();
};

#endif