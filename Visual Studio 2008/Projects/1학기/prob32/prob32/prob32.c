#include <stdio.h>
#include <stdlib.h>

void digits(int n);

void main(void)
{
	FILE *file;
	int i;
	int cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int value1, value2;

		fscanf(file, "%d %d", &value1, &value2);
		digits(value1*value2);
	}
	fclose(file);
}

void digits(int n)
{
	int digits=1;

	while(n>=10)
	{
		n/=10;
		digits++;
	}
	printf("%d %d\n", digits, n);
}