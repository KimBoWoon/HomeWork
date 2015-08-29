#include <stdio.h>
#include <stdlib.h>

int area(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2);

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
		int x1, y1, x2, y2;
		int a1, b1, a2, b2;

		fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(file, "%d %d %d %d", &a1, &b1, &a2, &b2);

		printf("%d\n", area(x1, y1, x2, y2, a1, b1, a2, b2));
	}
	fclose(file);
}

int area(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2)
{
	int a, b, c;
	int i, j, k, n;

	a=b=0;
	
	for(i=x1;i<=x2;i++)
	{
		for(j=a1;j<=a2;j++)
		{
			if(i==j)
				a++;
		}
	}
	for(k=y1;k<=y2;k++)
	{
		for(n=b1;n<=b2;n++)
		{
			if(k==n)
				b++;
		}
	}
	
	if(a==0 || b==0)
		return 0;
	else
		return (a-1)*(b-1);
}