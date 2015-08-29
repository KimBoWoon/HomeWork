/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                       라이프 게임                       *
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
		char data[101][101]={0}, temp[101][101]={0};
		int width, height, time, count=0, j, h, k, n;

		fscanf(file, "%d %d %d", &height, &width, &time);

		for(j=0;j<height;j++)
			fscanf(file, "%s", data[j]);
		for(j=0;j<height;j++)
		{
			for(h=0;h<width;h++)
				temp[j][h]='X';
		}
		for(k=0;k<time;k++)
		{
			for(j=0;j<height;j++)
			{
				for(h=0;h<width;h++)
				{
					n=0;

					if(data[j-1][h-1]=='O')
						n++;
					if(data[j-1][h]=='O')
						n++;
					if(data[j-1][h+1]=='O')
						n++;
					if(data[j][h-1]=='O')
						n++;
					if(data[j][h+1]=='O')
						n++;
					if(data[j+1][h-1]=='O')
						n++;
					if(data[j+1][h]=='O')
						n++;
					if(data[j+1][h+1]=='O')
						n++;

					if(n<=1)
						temp[j][h]='X';
					else if((n==2 || n==3) && data[j][h]=='O')
						temp[j][h]='O';
					else if(n==3 && data[j][h]=='X')
						temp[j][h]='O';
					else if(n>=4)
						temp[j][h]='X';
				}
			}
			for(j=0;j<height;j++)
			{
				for(h=0;h<width;h++)
					data[j][h]=temp[j][h];
			}
		}
		for(j=0;j<height;j++)
		{
			for(h=0;h<width;h++)
			{
				if(data[j][h]=='O')
					count++;
			}
		}
		printf("%d\n", count);
		for(j=0;j<height;j++)
		{
			for(h=0;h<width;h++)
				printf("%c", data[j][h]);
			puts("");
		}
	}
	fclose(file);
}