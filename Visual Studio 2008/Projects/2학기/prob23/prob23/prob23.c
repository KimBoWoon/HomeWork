/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     시험 점수 분포                      *
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
		int h, j, cases2, temp, value, count=1;
		int data[100]={0};

		fscanf(file, "%d", &cases2);

		for(j=0;j<cases2;j++)
		{
			fscanf(file, "%d", &value);

			data[j]=value;
		}
		for(j=0;j<=cases2-1;j++)
		{
			for(h=0;h<cases2-1;h++)
			{
				if(data[j]<data[h])
				{
					temp=data[j];
					data[j]=data[h];
					data[h]=temp;
				}
			}
		}
		if(cases2==1)
			printf("%d %d ", data[0], count);
		else
		{
			for(j=0;j<cases2-1;j++)
			{
				if(data[j]==data[j+1])
					count++;
				else
				{
					printf("%d %d ", data[j], count);
					count=1;
				}
				if(j==cases2-2)
					printf("%d %d ", data[j+1], count);
			}
		}
		puts("");
	}
	fclose(file);
}