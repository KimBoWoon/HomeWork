#include <stdio.h>
#include <stdlib.h>

void compute(int year);

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
		int a;

		fscanf(file, "%d", &a);

		compute(a);
	}
	fclose(file);
}
void compute(int year)
{
	int i, sum=5;

	for(i=1582;i<year;i++)
	{
		if(i%4==0 && i%100!=0 || i%400==0)
			sum+=366;
		else
			sum+=365;
	}

	printf("%d\n", sum%7);
}