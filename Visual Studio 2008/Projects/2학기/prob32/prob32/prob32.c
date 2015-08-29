/**********************************************************
*              ÄÄÇ»ÅÍ°øÇÐºÎ 20113259 ±èº¸¿î               *
*                        Çà·Ä µ¡¼À                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

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
		int data[100][100]={0}, data2[100][100]={0};
		int row, col, value, j, h;

		fscanf(file, "%d %d", &row, &col);

		for(j=0;j<row;j++)
		{
			for(h=0;h<col;h++)
				fscanf(file, "%d", &data[j][h]);
		}
		for(j=0;j<row;j++)
		{
			for(h=0;h<col;h++)
				fscanf(file, "%d", &data2[j][h]);
		}
		for(j=0;j<row;j++)
		{
			for(h=0;h<col;h++)
				data[j][h]+=data2[j][h];
		}
		for(j=0;j<row;j++)
		{
			for(h=0;h<col;h++)
				printf("%d ", data[j][h]);
			puts("");
		}
	}
	fclose(file);
}