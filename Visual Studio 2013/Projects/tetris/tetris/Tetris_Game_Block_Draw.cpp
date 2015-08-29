/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "Tetris_Game.h"
#include "Tetris_Key.h"
#include "Tetris_Block.h"
#include "Tetris_Interface.h"

bool O_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화 시켜준다
	if (collision(ORotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ORotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 1 || hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void O_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ORotate[state][i][j] == 1)
				hold[y + i][x + j] = 3;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool L_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화
	if (collision(LRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (LRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void L_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (LRotate[state][i][j] == 1)
				hold[y + i][x + j] = 4;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool J_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기하
	if (collision(JRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (JRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void J_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (JRotate[state][i][j] == 1)
				hold[y + i][x + j] = 5;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool Z_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화
	if (collision(ZRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ZRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void Z_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ZRotate[state][i][j] == 1)
				hold[y + i][x + j] = 6;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool S_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화
	if (collision(SRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (SRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void S_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (SRotate[state][i][j] == 1)
				hold[y + i][x + j] = 7;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool I_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화
	if (collision(IRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (IRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void I_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (IRotate[state][i][j] == 1)
				hold[y + i][x + j] = 8;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool T_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold를 초기화
	if (collision(TRotate, state, hold, x, y))//충돌검사
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (TRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
	return false;
}
void T_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//블럭을 특정값으로 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (TRotate[state][i][j] == 1)
				hold[y + i][x + j] = 9;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//팔레트2 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				wattroff(win1, COLOR_PAIR(1));//팔레트2 설정을 종료한다
			}
		}
	}
}
bool Block::collision(const int block[4][4][4], int state, int hold[20][20], int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[state][i][j] == 1)
			{
				if (hold[i + y][j + x] != 0)
					return true; //충돌
			}
		}
	}
	return false;
}
void Block::initialization(int hold[20][20])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (hold[i][j] >= 3 && hold[i][j] <= 9)//블럭에 특정값이 들어가 있으면 아무 작업도 하지 않는다
				;
			else if (i == 0 || i == height - 1 || j == width - 1)
				hold[i][j] = 2;
			else
				hold[i][j] = 0;
		}
	}
}