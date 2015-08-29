/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                    주사위 숫자 분포                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *file;
	int i, j, a;
	int cases;
	int value[2], b[11]={0};

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(file, "%d", &a);

		for(j=0;j<a;j++)
		{
			fscanf(file, "%d %d", &value[0], &value[1]);

			b[(value[0]+value[1])-2]++;
		}
		for(j=0;j<11;j++)
		{
			printf("%d ", b[j]);
			b[j]=0;
		}
		puts("");
	}
	fclose(file);
}