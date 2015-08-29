#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file;
	int i, j, k;
	int a, b, c, d;
	int cases;
	int sum;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		sum=0;
		fscanf(file, "%d %d %d %d", &a, &b, &c, &d);

		for(j=a;j<=b;j++)
		{
			for(k=c;k<=d;k++)
			{
				if(j==k)
					sum++;
			}
		}
		printf("%d\n", sum-1);
	}
	fclose(file);
}