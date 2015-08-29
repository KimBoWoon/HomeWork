#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file;
	int i, j;
	int a, b;
	int data, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(file, "%d %d %d", &a, &b, &data);

		for(j=a;j<=b;j++)
		{
			if(j==data)
			{
				printf("1\n");
				break;
			}
			if(j==b)
				printf("0\n");
		}
	}
	fclose(file);
}