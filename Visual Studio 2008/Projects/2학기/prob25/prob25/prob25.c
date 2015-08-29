/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                         런(Run)                         *
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