#include <stdio.h>
#include <stdlib.h>

int compute(int n);

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
		int value;

		fscanf(file, "%d", &value);

		printf("%d\n", compute(value));
	}
	fclose(file);
}
int compute(int n)
{
	int j, k, count, count2, mul, a, b, c;

	c=n;

	while(1)
	{
		count=count2=0;
		mul=1;
		a=n;

		while(a>=10)
		{
			a/=10;
			count++;
		}
		for(j=0;j<count;j++)
			mul*=10;
		for(k=0;k<=count;k++)
		{
			b=n;
			b/=mul;
			mul/=10;
			b%=10;
			if(b==1)
				count2++;
			else if(b!=1)
				count2=0;
			if(count2==2)
				return n;
		}
		n+=c;
	}
}