#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data, sum, sum2;
	int a, b, c, d, e;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d", &data);

		fscanf(in_file, "%d", &sum);

		a=0, b=0, c=0, d=0, e=0;

		for(j=0;j<data-1;j++)
		{
			fscanf(in_file, "%d", &sum2);

			if(sum>=sum2)
				a++;
			if(sum<=sum2)
				b++;
			if(sum==sum2)
				c++;
			if(abs(sum-sum2)>5)
				d++;
			if((sum%sum2)==0)
				e++;
			else if ((sum2%sum)==0)
				e++;

			sum=sum2;
		}
		printf("%d %d %d %d %d\n", a, b, c, d, e);
	}
	fclose(in_file);
}