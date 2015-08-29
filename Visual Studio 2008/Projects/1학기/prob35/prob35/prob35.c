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
		int value, value2;
		int mul=1;
		int a=1, b, c=1, d;

		fscanf(file, "%d %d", &value, &value2);

		mul=value*value2;
		d=mul;

		while(d>=10)
		{
			d/=10;
			a++;
		}
		for(b=1;b<=a/2;b++)
			c*=10;

		printf("%d\n", mul/c+mul%c);
	}
	fclose(file);
}