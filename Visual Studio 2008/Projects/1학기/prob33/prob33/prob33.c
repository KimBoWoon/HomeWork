#include <stdio.h>
#include <stdlib.h>

int k(int n);

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
		printf("%d\n", k(value));
	}
	fclose(file);
}
int k(int n)
{
	int a, b, i, j, k;
	int count, count2, count3=1;

	for(i=1;;i++)
	{
		a=i;
		count=0;
		count2=1;

		while(a>=10)
		{
			a/=10;
			count++;
		}
		if(n<10)
		{
			if(n==i)
				return i;
		}
		else
		{
			for(j=0;j<count;j++)
				count2*=10;
			for(k=0;k<=count;k++)
			{
				b=i;
				b/=count2;
				count2/=10;
				b%=10;
				if(n==count3)
					return b;
				count3++;
			}
		}
	}
}