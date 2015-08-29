#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data;
	int a, b, c, d;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=1;i<=cases;i++)
	{
		fscanf(in_file, "%d", &data);
		c=d=1;

		for(j=1;j<=data/2;j++)
		{
			for(a=d;a<=data/2;a++)
				printf("*");
			for(b=1;b<=c;b++)
				printf("+");
			for(a=d;a<=data/2;a++)
				printf("*");
			printf("\n");
			c+=2;
			d++;
		}
		for(j=0;j<=data/2;j++)
		{
			for(a=d;a<=data/2;a++)
				printf("*");
			for(b=1;b<=c;b++)
				printf("+");
			for(a=d;a<=data/2;a++)
				printf("*");
			printf("\n");
			c-=2;
			d--;
		}
	}
	fclose(in_file);
}