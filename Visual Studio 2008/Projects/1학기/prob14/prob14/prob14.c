#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data;
	int a, b, c, d, e;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d", &data);
		d=e=0;
		
		for(j=0;j<=data/2;j++)
		{
			if(j>0)
			{
				for(c=0;c<j;c++)
				{
					printf("-");
				}
			}
			printf("*");
			for(a=d;a<data/2;a++)
			{
				printf("+");
				for(b=0;b<1;b++)
				{
					printf("*");
				}
			}
			if(j>0)
			{
				for(c=0;c<j;c++)
				{
					printf("-");
				}
			}
			d++;
			printf("\n");
		}
		for(j=0;j<data/2;j++)
		{
			for(c=1+e;c<data/2;c++)
			{
					printf("-");
			}
			printf("*");
			for(a=-1+d;a<=data/2;a++)
			{
				printf("+");
				for(b=0;b<1;b++)
				{
					printf("*");
				}
			}
			for(c=1+e;c<data/2;c++)
			{
					printf("-");
			}
			d--;
			e++;
			printf("\n");
		}
	}
	fclose(in_file);
}