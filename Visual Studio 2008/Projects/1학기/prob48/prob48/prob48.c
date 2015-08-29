#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(int value);

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
		int value;

		fscanf(file, "%d", &value);

		compute(value);
	}
}
void compute(int value)
{
	int temp=value, f=0, c=0;
	int i;

	for(i=1;i<=value;i++)
	{
		f+=(floor(log(i)/log(2))+1);
		c+=(ceil(log(i)/log(2))+1);
	}
	printf("%d %d\n", f, c);
}