/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     날짜수 계산하기                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void compute(int year, int month, int day, int year2, int month2, int day2);

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
		int year, month, day, year2, month2, day2;

		fscanf(file, "%d %d %d %d %d %d", &year, &month, &day, &year2, &month2, &day2);

		compute(year, month, day, year2, month2, day2);
	}
	fclose(file);
}
void compute(int year, int month, int day, int year2, int month2, int day2)
{
	int y,m;
	int sum=0;

	for(y=year;y<year2;y++)
	{
		if(y%4==0 && y%100!=0 || y%400==0)
			sum+=366;
		else
			sum+=365;
	}
	for(m=1;m<month;m++)
	{
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			sum-=31;
		else if(m==4 || m==6 || m==9 || m==11)
			sum-=30;
		else if(m==2 && (year%4==0 && year%100!=0 || year%400==0))
			sum-=29;
		else if(m==2 && !(year%4==0 && year%100!=0 || year%400==0))
			sum-=28;
	}
	for(m=1;m<month2;m++)
	{
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			sum+=31;
		else if(m==4 || m==6 || m==9 || m==11)
			sum+=30;
		else if(m==2 && (year2%4==0 && year2%100!=0 || year2%400==0))
			sum+=29;
		else if(m==2 && !(year2%4==0 && year2%100!=0 || year2%400==0))
			sum+=28;
	}
	sum=sum-day+day2+1;

	printf("%d\n", sum);
}