#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year);

void main(void)
{
	FILE *in_file;
	int i;
	int cases;

	in_file = fopen("input.txt", "r");
	if (in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int year;

		fscanf(in_file, "%d", &year);

		printf("%d\n", isLeapYear(year));
	}
	fclose(in_file);
}

int isLeapYear(int year)
{
	return (year%4==0 && year%100!=0 || year%400==0);
}