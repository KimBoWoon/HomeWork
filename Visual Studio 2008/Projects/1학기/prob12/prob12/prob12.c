#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data;
	int a, b=1;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=1;i<=cases;i++)
	{
		fscanf(in_file, "%d", &data);

		b=1;

		for(j=1;j<=data;j++)
		{
			if(j<=2 || j==data)
			{
				for(a=1;a<=j;a++)
				{
					printf("*");
				}
			}
			else
			{
				printf("*");
				for(a=0;a<b;a++)
				{
					printf("+");
				}
				printf("*");
				b++;
			}
			printf("\n");
		}
	}

	fclose(in_file);
}