#include <stdio.h>
#include <stdlib.h>

int cross(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2);
int cross2(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2);

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
		int a1, b1, a2, b2;

		fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(file, "%d %d %d %d", &a1, &b1, &a2, &b2);

		if(cross(x1, y1, x2, y2, a1, b1, a2, b2))
			printf("1\n");
		else if(cross2(x1, y1, x2, y2, a1, b1, a2, b2))
			printf("2\n");
		else
			printf("0\n");
	}
	fclose(file);
}

int cross(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2)
{
	int temp;

	if(x1==x2)
	{
		if(a2<a1)
		{
			temp=a1;
			a1=a2;
			a2=temp;
		}
		if(y2<y1)
		{
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if((a1<x1 && x1<a2) && (y1<b1 && b1<y2))
			return 1;
		else
			return 0;
	}
	else if(b1==b2)
	{
		if(x2<x1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
		}
		if(y2<y1)
		{
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if((x1<a1 && a1<x2) && (b1<y1 && y1<b2))
			return 1;
		else
			return 0;
	}
}
int cross2(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2)
{
	int temp;

	if(x1==x2)
	{
		if(a2<a1)
		{
			temp=a1;
			a1=a2;
			a2=temp;
		}
		if(y2<y1)
		{
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if((x1==a1 && (y1<=b1 && y2>=b1)) || (x1==a2 && (y1<=b2 && y2>=b2)))
			return 1;
		else if((x1==a1 && (x1>=a1 && x1>=a2)) || (x2==a1 && (x1>=a1 && x1>=a2)))
			return 1;
		else
			return 0;
	}
	else
	{
		if(x2<x1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
		}
		if(y2<y1)
		{
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if((x1==a1 && (b1<=y1 && y1<=b2)) || (x2==a1 && (b1<=y1 && y1<=b2)))
			return 1;
		else if((y1==b1 && (x1<=a1 && x2>=a1)) || (y2==b2 && (x1<=a2 && x2>=a2)))
			return 1;
		else
			return 0;
	}
}