#include <stdio.h>
#include <stdlib.h>

void compute(int year, int month);

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
	int a, i, n=1, temp=year, temp2=month;

	if(month<=2)
	{
		temp--;
		temp2+=12;
	}

	a=((21*(temp/100)/4)+(5*(temp%100)/4)+(26*(temp2+1)/10)+1-1)%7;

	printf("%d %d\n", year, month);

	for(;;)
	{
		for(i=1;i<=7;i++)
		{
			if(a--<1)
				printf("%d ", n++);
			else
				printf("0 ");
			if(month==2 && (year%4==0 && year%100!=0 || year%400==0))
			{
				if(n>=30)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
			else if(month==2 && !(year%4==0 && year%100!=0 || year%400==0))
			{
				if(n>=29)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
			else if(month!=2 && month<=7 && month%2==0)
			{
				if(n>=31)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
			else if(month!=2 && month<=7 && month%2==1)
			{
				if(n>=32)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
			else if(month!=2 && month>=8 && month%2==0)
			{
				if(n>=32)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
			else if(month!=2 && month>=8 && month%2==1)
			{
				if(n>=31)
				{
					while(i++<7)
						printf("0 ");
					puts("");
					return;
				}
			}
		}
		puts("");
	}
}