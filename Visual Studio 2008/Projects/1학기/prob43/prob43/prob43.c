#include <stdio.h>
#include <stdlib.h>

int compute(int n);

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
		int value, value2;

		fscanf(file, "%d %d", &value, &value2);

		printf("%d\n", compute(value*value2));
	}
	fclose(file);
}
int compute(int n)
{
	int a, b, c, j, k, m;
	int mul, count;

	a=n;
	count=0;
	m=mul=1;

	if(n<10)
		return 1;

	while(a>=10)
	{
		a/=10;
		count++;
	}
	for(j=0;j<count;j++)
		mul*=10;
	b=n;
	b/=mul;
	mul/=10;
	b%=10;
	c=n;
	c/=mul;
	c%=10;
	if(b<c)
	{
		for(k=1;k<count;k++)
		{
			b=n;
			b/=mul;
			mul/=10;
			b%=10;
			c=n;
			c/=mul;
			c%=10;

			if(b<c)
				continue;
			else
				return 0;
		}
	}
	else
	{
		for(k=1;k<count;k++)
		{
			b=n;
			b/=mul;
			mul/=10;
			b%=10;
			c=n;
			c/=mul;
			c%=10;

			if(b>c)
				continue;
			else
				return 0;
		}
	}
	return 1;
}