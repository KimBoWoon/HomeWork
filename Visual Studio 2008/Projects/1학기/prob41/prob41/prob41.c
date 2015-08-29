#include <stdio.h>
#include <stdlib.h>

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
		int value, value2, count=1, a, b;

		fscanf(file, "%d", &value);

		value2=value;
		a=value;
		b=value2;

		while(1)
		{
			count++;

			b=a;
			a/=10;
			b%=10;
			a=abs((a*10+b)-(b*10+a));

			if(a==0)
				break;
			else if(a==9)
				break;
		}

		printf("%d %d ", count, value);

		while(1)
		{
			count++;

			value2=value;
			value/=10;
			value2%=10;
			printf("%d ", abs((value*10+value2)-(value2*10+value)));
			value=abs((value*10+value2)-(value2*10+value));

			if(value==0)
				break;
			else if(value==9)
				break;
		}
		printf("\n");
	}
	fclose(file);
}