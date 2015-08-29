#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i;
	int cases;
	int a, b, c, d, e, f;
	int x, y, z, temp;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=1;i<=cases;i++)
	{
		fscanf(in_file, "%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

		x=((a-c)*(a-c))+((b-d)*(b-d));
		y=((a-e)*(a-e))+((b-f)*(b-f));
		z=((e-c)*(e-c))+((f-d)*(f-d));

		if(x>y)
		{
			temp=x;
			x=y;
			y=temp;
		}
		if(x>z)
		{
			temp=z;
			z=x;
			x=temp;
		}
		if(y>z)
		{
			temp=y;
			y=z;
			z=temp;
		}

		if((x+y)==z)
			printf("1\n");
		else if((x+y)<z)
			printf("2\n");
		else
			printf("3\n");
	}
	fclose(in_file);
}