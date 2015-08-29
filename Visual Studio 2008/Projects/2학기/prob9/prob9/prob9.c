/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 사각형 양탄자 출력하기                  *
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
		int h, j, k;

		fscanf(file, "%d", &k);

		for(j=0;j<k;j++)
			printf("+");
		puts("");
		for(h=0;h<k/2;h++)
		{
			printf("IX");
			for(j=0;j<k/2;j++)
			{
				if(j>0)
					printf("-X");
			}
			printf("I");
			puts("");
			if(h>=(k/2)-1)
				break;
			printf("I");
			for(j=0;j<k/2;j++)
			{
				if(j>0)
					printf("-X");
			}
			printf("-I");
			puts("");
		}
		for(j=0;j<k;j++)
			printf("+");
		puts("");
	}
}