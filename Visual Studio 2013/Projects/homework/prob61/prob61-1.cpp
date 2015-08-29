#include "prob61.h"

lifegame::lifegame()
{
}
void lifegame::runlifegame(int row, int col, int time, char gamecells[max_size][max_size])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			temp[i][j] = 'X';
	}
	for (int i = 0; i < time; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int h = 0; h < col; h++)
			{
				numalivecells = 0;

				if (gamecells[j - 1][h - 1] == 'O')
					numalivecells++;
				if (gamecells[j - 1][h] == 'O')
					numalivecells++;
				if (gamecells[j - 1][h + 1] == 'O')
					numalivecells++;
				if (gamecells[j][h - 1] == 'O')
					numalivecells++;
				if (gamecells[j][h + 1] == 'O')
					numalivecells++;
				if (gamecells[j + 1][h - 1] == 'O')
					numalivecells++;
				if (gamecells[j + 1][h] == 'O')
					numalivecells++;
				if (gamecells[j + 1][h + 1] == 'O')
					numalivecells++;

				if (numalivecells <= 1)
					temp[j][h] = 'X';
				else if ((numalivecells == 2 || numalivecells == 3) && gamecells[j][h] == 'O')
					temp[j][h] = 'O';
				else if (numalivecells == 3 && gamecells[j][h] == 'X')
					temp[j][h] = 'O';
				else if (numalivecells >= 4)
					temp[j][h] = 'X';
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				gamecells[i][j] = temp[i][j];
		}
	}
	printboard(row, col, gamecells);
}
void lifegame::printboard(int row, int col, char gamecells[max_size][max_size])
{
	numalivecells = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (gamecells[i][j] == 'O')
				numalivecells++;
		}
	}
	cout << numalivecells << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << gamecells[i][j];
		cout << endl;
	}
}