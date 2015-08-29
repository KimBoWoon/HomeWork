/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "block.h"

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
	blockcolor(win1, hold);
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
void Block::blockcolor(WINDOW* win1, int hold[20][20]) {
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
}