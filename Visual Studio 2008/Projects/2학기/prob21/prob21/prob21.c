/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                      달력출력하기                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void compute(int year, int month);
int lastday(int year, int month);

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
		int year, month;

		fscanf(file, "%d %d", &year, &month);

		compute(year, month);
	}
	fclose(file);
}
void compute(int year, int month)
{
	int a, i, n=1, temp=year, temp2=month, j, sum=5;

	for(i=1582;i<year;i++)
	{
		if(i%4==0 && i%100!=0 || i%400==0)
			sum+=366;
		else
			sum+=365;
	}
	for(j=1;j<month;j++)
	{
		if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
			sum+=31;
		else if(j==4 || j==6 || j==9 || j==11)
			sum+=30;
		else if(j==2 && (i%4==0 && i%100!=0 || i%400==0))
			sum+=29;
		else if(j==2 && !(i%4==0 && i%100!=0 || i%400==0))
			sum+=28;
	}

	a=sum%7;

	printf("%d %d\n", year, month);

	for(;;)
	{
		for(i=1;i<=7;i++)
		{
			if(a--<1)
				printf("%d ", n++);
			else
				printf("0 ");
			if(n==lastday(year, month))
			{
				while(i++<7)
					printf("0 ");
				puts("");
				return;
			}
		}			
		puts("");
	}
}
int lastday(int year, int month)
{
	switch(month)
	{
	case 1:
		return 32;
	case 3:
		return 32;
	case 5:
		return 32;
	case 7:
		return 32;
	case 8:
		return 32;
	case 10:
		return 32;
	case 12:
		return 32;
	case 2:
		if((year%4==0 && year%100!=0 || year%400==0))
			return 30;
		else
			return 29;
	default:
		return 31;
	}
}