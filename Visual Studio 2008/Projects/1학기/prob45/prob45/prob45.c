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
		int a, j, value, num, sum=0, num2;

		fscanf(file, "%d", &a);

		for(j=1;j<=a;j++)
		{
			fscanf(file, "%d", &value);

			if(j==1)
			{
				num=value;
				num2=j;
			}
			if(num<value)
			{
				num=value;
				num2=j;
			}
			sum+=value;
		}
		if(num>sum/2)
			printf("%d\n", num2);
		else
			printf("0\n");
	}
	fclose(file);
}