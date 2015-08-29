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

class Interface//게임화면애 관한 클래스
{
private:
	WINDOW *win1;	//게임표현화면
	WINDOW *win2;	//점수표현화면
	WINDOW *win3;	//닉네임표현화면
public:
	Interface()	//생성자를 이용해 새로운 윈도우를 만든다
	{
		win1 = newwin(20, 22, 2, 2);
		win2 = newwin(4, 10, 4, 30);
		win3 = newwin(4, 10, 10, 30);
	}
	~Interface()	//소멸자를 이용해 게임이 끝나면 화면을 제거한다
	{
		delwin(win1);//게임 표시 화면 제거
		delwin(win2);//점수 표시 화면 제거
		delwin(win3);//player표시 화면 제거
	}
	void PlayInterface(WINDOW *win1);//게임 화면 표시 함수
	void ScoreInterface(WINDOW *win2);//점수 표시 화면 함수
	void UsernameInterface(WINDOW *win3, char* name);//player이름 표시 화면 함수
	//다른 클래스나 함수에서 윈도우를 참조하기위해 Get함수를 만들었다
	WINDOW* Getwin1()	{ return win1; }
	WINDOW* Getwin2()	{ return win2; }
	WINDOW* Getwin3()	{ return win3; }
};