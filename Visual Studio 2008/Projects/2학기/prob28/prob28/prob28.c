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
		int h, j, cases2, temp, value, count=1;
		int data[100]={0};

		fscanf(file, "%d", &cases2);

		for(j=0;j<cases2;j++)
		{
			fscanf(file, "%d", &value);

			data[j]=value;
		}
		for(j=0;j<=cases2-1;j++)
		{
			for(h=0;h<cases2-1;h++)
			{
				if(data[j]<data[h])
				{
					temp=data[j];
					data[j]=data[h];
					data[h]=temp;
				}
			}
		}
		for(j=0;j<cases2;j++)
			printf("%d ", data[j]);
		puts("");
	}
	fclose(file);
}