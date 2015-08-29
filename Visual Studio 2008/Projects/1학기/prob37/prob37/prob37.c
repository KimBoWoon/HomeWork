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
		int prime=1;
		int divisor;

		fscanf(file, "%d", &value);

		for(divisor=2;divisor<value;divisor++)
		{
			if(value%divisor==0)
			{
				prime=0;
				break;
			}
		}
		printf("%d\n", prime);
	}
	fclose(file);
}