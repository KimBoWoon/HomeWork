#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i;
	int cases;
	int a, b, c, temp;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=1;i<=cases;i++)
	{
		fscanf(in_file, "%d %d %d", &a, &b, &c);

		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(a>c)
		{
			temp=c;
			c=a;
			a=temp;
		}
		if(b>c)
		{
			temp=b;
			b=c;
			c=temp;
		}

		if((a+b)<=c)
			printf("0\n");
		else if(a==b && b==c)
			printf("1\n");
		else if((a*a)+(b*b)==(c*c))
			printf("2\n");
		else if(a==b || a==c || b==c)
			printf("3\n");
		else
			printf("4\n");
	}
	fclose(in_file);
}