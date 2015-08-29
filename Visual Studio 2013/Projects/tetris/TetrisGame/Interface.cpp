/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "interface.h"

void Interface::PlayInterface(WINDOW *win1)//게임표시화면
{
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');//게임표시 화면에 경계선 설정

	wattron(win1, COLOR_PAIR(1));//팔레트1 설정으로 색깔을 입힌다

	for (int i = 1; i < 19; i++)//for문으로 간단하게 특수문자를 입력
		mvwprintw(win1, i, 1, "□□□□□□□□□□");

	wattroff(win1, COLOR_PAIR(1));//팔레트1 설정을 종료한다
}
void Interface::ScoreInterface(WINDOW *win2)//score를 나타내주는 화면
{
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');//점수 표시 화면 경계선 설정
	wattron(win2, COLOR_PAIR(3));//팔레트3 설정으로 색깔을 입힌다
	mvwprintw(win2, 1, 1, "score:");
	mvwprintw(win2, 2, 1, "%d", 0);
	wattroff(win2, COLOR_PAIR(3));//팔레트3 설정을 종료한다
}
void Interface::UsernameInterface(WINDOW *win3, char* name)//user을 나타내는 화면
{
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');//player 표시 화면 경계선 설정
	wattron(win3, COLOR_PAIR(3));//팔레트3 설정으로 색깔을 입힌다
	mvwprintw(win3, 1, 1, "name:");
	mvwprintw(win3, 2, 1, "%s", name);
	wattron(win3, COLOR_PAIR(3));//팔레트3 설정을 종료한다
}