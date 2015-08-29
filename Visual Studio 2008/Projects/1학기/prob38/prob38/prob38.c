#include <stdio.h>
#include <stdlib.h>

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
		int a, b, count=1, mul=1;

		fscanf(file, "%d", &value);

		a=value;

		while(a>=10)
		{
			a/=10;
			count++;
		}
		for(b=1;b<=count/2;b++)
			mul*=10;

		if(abs(value/mul-value%mul)<2)
			printf("1\n");
		else
			printf("0\n");
	}
	fclose(file);
}