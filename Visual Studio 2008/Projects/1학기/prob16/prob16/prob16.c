#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i;
	int cases, data;
	int a, b, sum, sum2;
	int y;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=1;i<=cases;i++)
	{
		fscanf(in_file, "%d", &data);
		y=0;

		for(a=1;a<=9;a++)
		{
			for(b=1;b<=9;b++)
			{
				if(a!=b)
				{
					sum=(1000*a)+(100*b)+(10*a)+(1*b);
					sum2=(1000*b)+(100*a)+(10*b)+(1*a);

					if((sum+sum2)==data)
					{
						if(a==1)
						{
							printf("%d %d\n", sum, sum2);
							y++;
						}
					}
				}
			}
			sum=sum2=0;
		}
		if(y==0)
			printf("%d %d\n", sum, sum2);
	}
	fclose(in_file);
}