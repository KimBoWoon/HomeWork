#include <stdio.h>
#include <stdlib.h>

void compute(int year, int month, int day);

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
		int a, b, c;

		fscanf(file, "%d %d %d", &a, &b, &c);

		compute(a, b, c);
	}
	fclose(file);
}
void compute(int year, int month, int day)
{
	int i, j, k, sum=5;

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
	for(k=1;k<day;k++)
		sum++;

	printf("%d\n", sum%7);
}