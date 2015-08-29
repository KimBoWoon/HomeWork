/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                     ��¥�� ����ϱ�                     *
**********************************************************/
/*#include <stdio.h>
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
}*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compute(int year, int month, int day, int year2, int month2, int day2);

int main()
{
	FILE *file;
	int OldSec, a=1;
	int i, cases;
	int year, month, day, year2, month2, day2;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	while (a--)
	{
		printf("���� ��¥�� �Է��ϼ���.\n");
		scanf("%d %d %d", &year, &month, &day);
		
		printf("�������� �Է��ϼ���.\n");
		scanf("%d %d %d", &year2, &month2, &day2);

		compute(year, month, day, year2, month2, day2);
	}
}
void compute(int year, int month, int day, int year2, int month2, int day2)
{
	int y,m;
	int sum=0;
	float max=640;

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

	printf("�������� %d�� ���ҽ��ϴ�.%0.2f\n", sum, ((max-sum)/max)*100);

	return 0;
}