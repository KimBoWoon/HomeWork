#include <stdio.h>
#include <stdlib.h>

int prob40(int value, int n);

int main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int value, n;

		fscanf(file, "%d %d", &value, &n);

		printf("%d\n", prob40(value, n-1));
	}
	fclose(file);
}
int prob40(int value, int n)
{
	int a, b, c, j, k;
	int count, mul;

	while(n--)
	{
		mul=1;
		c=count=0;
		a=value;

		while(a>=10)
		{
			a/=10;
			count++;
		}
		for(j=0;j<count;j++)
			mul*=10;
		for(k=0;k<=count;k++)
		{
			b=value;
			b/=mul;
			mul/=10;
			b%=10;
			c+=b;
		}
		value+=c;
	}
	return value;
}