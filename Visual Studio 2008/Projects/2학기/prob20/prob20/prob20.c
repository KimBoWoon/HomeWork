/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     일광절약시간제                      *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int compute(int year);

void main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int year;

		fscanf(file, "%d", &year);

		compute(year);
	}
	fclose(file);
}
int compute(int year)
{
	int a, b, i, march=0, october=0, count=1;

	a=((21*(year/100)/4)+(5*(year%100)/4)+(26*(3+1)/10)+1-1)%7;
	b=((21*(year/100)/4)+(5*(year%100)/4)+(26*(10+1)/10)+1-1)%7;

	for(;;)
	{
		for(i=1;i<=7;i++)
		{
			if(a--<1)
				march++;
			if(b--<1)
				october++;

			if(count==5 && i==1)
			{
				if(march+7<=31)
					march+=7;
				if(october+7<=31)
					october+=7;

				printf("%d %d\n", march, october);
				return 0;
			}
		}
		count++;
	}
}