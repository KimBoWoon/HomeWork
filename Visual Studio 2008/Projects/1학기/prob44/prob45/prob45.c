#include <stdio.h>
#include <stdlib.h>

int compute(int a, int b, int c, int d);

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
		int a, b, c, d;

		fscanf(file, "%d %d %d %d", &a, &b, &c, &d);

		printf("%d\n", compute(a, b, c, d));
	}
	fclose(file);
}
int compute(int a, int b, int c, int d)
{
	int e, count=0;

	while(1)
	{
		e=a;
		a=abs(a-b);
		b=abs(b-c);
		c=abs(c-d);
		d=abs(d-e);

		count++;

		if(a==0 && b==0 && c==0 && d==0)
			return count;
	}
}