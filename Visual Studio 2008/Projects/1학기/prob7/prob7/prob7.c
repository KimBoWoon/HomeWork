#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j, a;
	int cases, data;
	int sum;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d", &data);
		sum=0;
		
		for(a=0;a<data;a++)
		{
			fscanf(in_file, "%d", &j);

			sum+=j;
		}
		printf("%d\n", sum);
	}
	fclose(in_file);
}