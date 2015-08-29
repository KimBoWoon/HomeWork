#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j, value=0;
	int no_cases, no_data;
	int min, max;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &no_cases);

	for(i=0;i<no_cases;i++)
	{
		fscanf(in_file, "%d", &no_data);
		
		for(j=0;j<no_data;j++)
		{
			fscanf(in_file, "%d", &value);
			
			if(j==0)
				max=min=value;

			if(min>value)
				min=value;
			if(max<value)
				max=value;
		}

		printf("%d %d\n", max, min);
	}

	fclose(in_file);
}