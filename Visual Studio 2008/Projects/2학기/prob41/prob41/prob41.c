/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                        오셀로 게임                      *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9
#define BLACK 'X'
#define WHITE 'O'

void PlayOthello(int row, int col, char stone1, char stone2, int board[][BOARD_SIZE]);
void game(int board[][BOARD_SIZE]);
void print(int board[][BOARD_SIZE]);

void main(void)
{
	FILE *in_file=fopen("input.txt", "r");
	int i, cases;

	if(in_file == NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int j, move, row, col;
		int board[BOARD_SIZE][BOARD_SIZE]={0};

		game(board);

		fscanf(in_file, "%d", &move);

		for(j=1; j<=move; j++)
		{
			fscanf(in_file, "%d %d", &row, &col);
			if(j%2==1)
				PlayOthello(row, col, BLACK, WHITE, board);

			else
				PlayOthello(row, col, WHITE, BLACK, board);
		}
		print(board);
	}
	fclose(in_file);
}

void PlayOthello(int row, int col, char stone1, char stone2, int board[][BOARD_SIZE])
{
	int cnt, l, h, l2, h2;

	cnt=0;

	for(l=row-1, h=col-1; l>0, h>0; l--, h--)
	{
		if(board[l][h]==stone1)
		{
			for(l2=l+1,h2=h+1; l2<=row,h2<=col; l2++, h2++)
				if(board[l2][h2]==stone2)
					cnt++;
			if(cnt==row-l-1)
				for(l2=l+1,h2=h+1; l2<=row,h2<=col; l2++, h2++)
					board[l2][h2]=stone1;
			break;
		}
	}
	cnt=0;
	for(h=col-1; h>0; h--)
	{
		if(board[row][h]==stone1)
		{
			for(h2=h+1; h2<=col; h2++)
				if(board[row][h2]==stone2)
					cnt++;
			if(cnt==col-h-1)
				for(h2=h+1; h2<=col; h2++)
					board[row][h2]=stone1;
			break;
		}
	}
	cnt=0;
	for(l=row+1, h=col-1; l<9, h>0; l++, h--)
	{
		if(board[l][h]==stone1)
		{
			for(l2=l-1,h2=h+1; l2>=row, h2<=col; l2--, h2++)
				if(board[l2][h2]==stone2)
					cnt++;
			if(cnt==l-row-1)
				for(l2=l-1,h2=h+1; l2>=row, h2<=col; l2--, h2++)
					board[l2][h2]=stone1;
			break;
		}
	}
	cnt=0;
	for(l=row-1; l>0; l--)
	{
		if(board[l][col]==stone1)
		{
			for(l2=l+1; l2<=row; l2++)
				if(board[l2][col]==stone2)
					cnt++;
			if(cnt==row-l-1)
				for(l2=l+1; l2<=row; l2++)
					board[l2][col]=stone1;
			break;
		}
	}
	cnt=0;
	for(l=row+1; l<9; l++)
	{
		if(board[l][col]==stone1)
		{
			for(l2=l-1; l2>=row; l2--)
				if(board[l2][col]==stone2)
					cnt++;
			if(cnt==l-row-1)
				for(l2=l-1; l2>=row; l2--)
					board[l2][col]=stone1;
			break;
		}
	}
	cnt=0;
	for(l=row-1, h=col+1; l>0, h<9; l--, h++)
	{
		if(board[l][h]==stone1)
		{
			for(l2=l+1,h2=h-1; l2<=row,h2>=col; l2++, h2--)
				if(board[l2][h2]==stone2)
					cnt++;
			if(cnt==row-l-1)
				for(l2=l+1,h2=h-1; l2<=row,h2>=col; l2++, h2--)
					board[l2][h2]=stone1;
			break;
		}
	}
	cnt=0;
	for(h=col+1; h<9; h++)
	{
		if(board[row][h]==stone1)
		{
			for(h2=h-1; h2>=col; h2--)
				if(board[row][h2]==stone2)
					cnt++;
			if(cnt==h-col-1)
				for(h2=h-1; h2>=col; h2--)
					board[row][h2]=stone1;
			break;
		}
	}
	cnt=0;
	for(l=row+1, h=col+1; l<9, h<9; l++, h++)
	{
		if(board[l][h]==stone1)
		{
			for(l2=l-1,h2=h-1; l2>=row, h2>=col; l2--, h2--)
				if(board[l2][h2]==stone2)
					cnt++;
			if(cnt==l-row-1)
				for(l2=l-1,h2=h-1; l2>=row, h2>=col; l2--, h2--)
					board[l2][h2]=stone1;
			break;
		}
	}
}
void print(int board[][BOARD_SIZE])
{
	int i, j, count=0, count2=0;

	for(i=1;i<9;i++)
	{
		for(j=1;j<9;j++)
		{
			if(board[i][j]==BLACK)
				count++;
			else if(board[i][j]==WHITE)
				count2++;
		}
	}
	printf("%d %d\n", count, count2);
	for(i=1;i<9;i++)
	{
		for(j=1;j<9;j++)
			printf("%c", board[i][j]);
		puts("");
	}
}
void game(int board[][BOARD_SIZE])
{
	int i, j;

	for(i=1;i<9;i++)
	{
		for(j=1;j<9;j++)
		{
			if(i==4 && j==4 || i==5 && j==5)
				board[i][j]=WHITE;
			else if(i==4 && j==5 || i==5 && j==4)
				board[i][j]=BLACK;
			else
				board[i][j]='+';
		}
	}
}