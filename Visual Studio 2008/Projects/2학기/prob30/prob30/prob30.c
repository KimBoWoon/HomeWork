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
		int data[100][100]={0};
		int j, h, value, sum=0, sum2=0, count=0, n=0;

		fscanf(file, "%d", &value);

		for(j=0;j<value;j++)
		{
			for(h=0;h<value;h++)
				fscanf(file, "%d", &data[j][h]);
		}
		for(j=0;j<value;j++)
		{
			if(j==0)
			{
				for(h=0;h<value;h++)
					sum+=data[j][h];
			}
			for(h=0;h<value;h++)
				sum2+=data[j][h];

			if(sum==sum2)
				count++;
			sum2=0;
		}
		for(j=0;j<value;j++)
		{
			for(h=0;h<value;h++)
				sum2+=data[h][j];

			if(sum==sum2)
				count++;
			sum2=0;
		}
		for(j=0;j<value;j++)
		{
			for(h=0;h<1;h++)
			{
				sum2+=data[n][n];
				n++;
			}
		}
		if(sum==sum2)
			count++;
		sum2=0;
		n=value-1;
		for(j=0;j<value;j++)
		{
			for(h=0;h<1;h++)
			{
				sum2+=data[j][n];
				n--;
			}
		}
		if(sum==sum2)
			count++;
		sum2=0;
		if(count==(value*2+2))
			printf("%d\n", sum);
		else
			printf("-1\n");
	}
	fclose(file);
}