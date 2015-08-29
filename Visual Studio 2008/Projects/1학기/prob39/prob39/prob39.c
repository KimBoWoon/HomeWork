#include <stdio.h>
#include <stdlib.h>

int prob39(int value);

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
		int value;

		fscanf(file, "%d", &value);

		printf("%d\n", prob39(value));
	}
	fclose(file);
}
int prob39(int value)
{
	int count, count2=0, mul, a, b, c, d, e;

	if(value<10)
		return 0;

	while(1)
	{
		a=value;
		mul=e=1;
		count=0;

		while(a>=10)
		{
			a/=10;
			count++;
		}
		for(b=0;b<count;b++)
			mul*=10;
		for(d=0;d<=count;d++)
		{
			c=value;
			c/=mul;
			mul/=10;
			c%=10;
			e*=c;
		}
		value=e;
		count2++;
		if(value<10)
			return count2;
	}
}