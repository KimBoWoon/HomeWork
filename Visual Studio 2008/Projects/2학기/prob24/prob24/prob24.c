/**********************************************************
*               컴퓨터공학부 20113259 김보운              *
*                         이동 평균                       *
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
		int data[256];
		int j, cases2, range, value, result=0, n=0, h, count=0;

		fscanf(file, "%d", &cases2);

		for(j=0;j<cases2;j++)
		{
			fscanf(file, "%d", &value);

			data[j]=value;
		}

		fscanf(file, "%d", &range);

		for(j=0;j<(cases2-range+1);j++)
		{
			for(h=j;h<range+j;h++)
				result+=data[h];
			count++;
			result=0;
		}
		printf("%d ", count);
		for(j=0;j<(cases2-range+1);j++)
		{
			for(h=j;h<range+j;h++)
				result+=data[h];
			printf("%d ", result/range);
			result=0;
		}
		puts("");
	}
}