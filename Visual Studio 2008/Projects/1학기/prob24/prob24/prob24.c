#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

int test(int x1, int y1, int x2, int y2, int px, int py);
int interval(int a, int b, int c);

void main(void)
{
	FILE *file;
	int i;
	int cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int x1, y1, x2, y2;
		int px, py;

		fscanf(file, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &px, &py);

		printf("%d\n", test(x1, y1, x2, y2, px, py));
	}
	fclose(file);
}

int test(int x1, int y1, int x2, int y2, int px, int py)
{
	int minx, maxx, miny, maxy;

	if(px==x1 && py==y1 || px==x2 && py==y2)
		return 2;

	if(x1==x2)
	{
		miny=MIN(y1, y2);
		maxy=MAX(y1, y2);

		if(px==x1)
		{
			return interval(miny, maxy, py);
		}
		else
		{
			return 0;
		}
	}
	else if(y1==y2)
	{
		minx=MIN(x1, x2);
		maxx=MAX(x1, x2);

		if(py==y1)
		{
			return interval(minx, maxx, px);
		}
		else
		{
			return 0;
		}
	}
}

int interval(int a, int b, int c)
{
	return (c>=a && c<=b)? 1:0;
}