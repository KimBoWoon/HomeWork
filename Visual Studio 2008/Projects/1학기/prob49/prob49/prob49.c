#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(int x1, int y1, int x2, int y2);

void main(void)
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

		fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);

		compute(x1, y1, x2, y2);
	}
}
void compute(int x1, int y1, int x2, int y2)
{
	int d1, d2, d3;

	d1=fabs(x2-x1)+fabs(y2-y1);
	d2=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))+0.5;
	d3=max(fabs(x2-x1), fabs(y2-y1));

	printf("%d %d %d\n", d2, d1, d3);
}