/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                  직선 그래프 출력하기                   *
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
		int data, j, h, star,star2;
		fscanf(file, "%d", &data);

		star=data;
		star2=data;

		for(h=0;h<data/2;h++)
		{
			for(j=0;j<data/2;j++)
				printf(".");
			printf("I");
			for(j=0;j<data/2;j++)
			{
				if(star/2-1==j)
				{
					printf("*");
					star -= 2;
				}
				else
					printf(".");
			}
			puts("");
		}
		for(j=0;j<data/2;j++)
			printf("+");
		printf("O");
		for(j=0;j<data/2;j++)
			printf("+");
		puts("");
		for(h=0;h<data/2;h++)
		{
			for(j=0;j<data/2;j++)
			{
				if(star2/2-1==j)
				{
					printf("*");
					star2 -= 2;
				}
				else
					printf(".");
			}
			printf("I");
			for(j=0;j<data/2;j++)
				printf(".");
			puts("");
		}
	}
}