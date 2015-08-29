/**********************************************************
*              ÄÄÇ»ÅÍ°øÇÐºÎ 20113259 ±èº¸¿î               *
*                        Çà·Ä °ö¼À                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int data[][100], int row, int s);
void multiply(int data[][100], int data2[][100], int temp[][100], int row, int s, int col);
void print(int temp[][100], int row, int col);

int main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int data[100][100]={0}, data2[100][100]={0}, temp[100][100]={0};
		int row, col, s;

		fscanf(file, "%d %d %d", &row, &s, &col);

		read(file, data, row, s);
		read(file, data2, s, col);
		multiply(data, data2, temp, row, s, col);
		print(temp, row, col);

	}
	fclose(file);
}
void read(FILE *file, int data[][100], int row, int s)
{
	int j, h;

	for(j=0;j<row;j++)
	{
		for(h=0;h<s;h++)
			fscanf(file, "%d", &data[j][h]);
	}
}
void multiply(int data[][100], int data2[][100], int temp[][100], int row, int s, int col)
{
	int v, j, h;

	for(v=0;v<row;v++)
	{
		for(j=0;j<col;j++)
		{
			for(h=0;h<s;h++)
				temp[v][j]+=data[v][h]*data2[h][j];
		}
	}
}
void print(int temp[][100], int row, int col)
{
	int j, h;

	for(j=0;j<row;j++)
	{
		for(h=0;h<col;h++)
			printf("%d ", temp[j][h]);
		puts("");
	}
}