#include <stdio.h>
#include <stdlib.h>

int inside(int x1, int y1, int x2, int y2, int px, int py);
int onedge(int x1, int y1, int x2, int y2, int px, int py);
int oncorner(int x1, int y1, int x2, int y2, int px, int py);
int outside(int x1, int y1, int x2, int y2, int px, int py);
int point(int x1, int y1, int x2, int y2);
int segment(int a, int b, int c);

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

		fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(file, "%d %d", &px, &py);

		if(inside(x1, y1, x2, y2, px, py))
			printf("0\n");
		else if(onedge(x1, y1, x2, y2, px, py))
			printf("2\n");
		else if(oncorner(x1, y1, x2, y2, px, py))
			printf("3\n");
		else if(outside(x1, y1, x2, y2, px, py))
			printf("1\n");
	}
	fclose(file);
}

int inside(int x1, int y1, int x2, int y2, int px, int py)
{
	if((px>x1) && (px<x2) && (py>y1) && (py<y2))
		return 1;
	else
		return 0;
}
int onedge(int x1, int y1, int x2, int y2, int px, int py)
{
	if(px==x1 || px==x2)
	{
		if(segment(y1, y2, py))
			return 1;
		else
			return 0;
	}
	else if(py==y1 || py==y2)
	{
		if(segment(x1, x2, px))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int oncorner(int x1, int y1, int x2, int y2, int px, int py)
{
	if(point(x1, y1, px, py))
		return 1;
	else if(point(x2, y2, px, py))
		return 1;
	else if(point(x1, y2, px, py))
		return 1;
	else if(point(x2, y1, px, py))
		return 1;
	else
		return 0;
}
int outside(int x1, int y1, int x2, int y2, int px, int py)
{
	if((px>x1 || px>x2 && py>y1 || py>y2) || (px<x1 || px<x2 && py<y1 || py<y2))
		return 1;
	else
		return 0;
}
int point(int x1, int y1, int x2, int y2)
{
	if((x1==x2) && (y1==y2))
		return 1;
	else
		return 0;
}
int segment(int a, int b, int c)
{
	if(c>a && c<b)
		return 1;
	else
		return 0;
}