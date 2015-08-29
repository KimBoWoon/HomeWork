#include <stdio.h>
#include <stdlib.h>

void carry(int total, int value, int value2);

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
		int a, b, c, d;

		fscanf(file, "%d %d %d %d", &a, &b, &c, &d);

		carry(a+b+c+d, a+b, c+d);
	}
	fclose(file);
}

void carry(int total, int value, int value2)
{
	int sum, sum2, temp, a=1, carry=0;

	while(total>=10)
	{
		total/=10;
		a++;
	}
	printf("%d ", a);
	if(value<value2)
	{
		temp=value;
		value=value2;
		value2=temp;
	}
	while(a>1)
	{
		sum=sum2=0;
		sum+=value%10;
		value/=10;
		sum2+=value2%10;
		value2/=10;

		if(sum+sum2+carry>=10)
		{
			printf("1 ");
			carry=1;
		}
		else
		{
			printf("0 ");
			carry=0;
		}
		a--;
	}
	puts("");
}