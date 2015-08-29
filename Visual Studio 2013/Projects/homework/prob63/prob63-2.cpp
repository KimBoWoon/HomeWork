#include "prob63.h"

squareodd::squareodd() : size(0)
{
}
squareodd::squareodd(int n) : size(n)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			square[i][j]=0;
	}
	makesquare();
	if(!checksquare())
		exit(1);
}
void squareodd::printsquare() const
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<square[i][j]<<" ";
		cout<<endl;
	}
}
void squareodd::makesquare()
{
	int x=size/2, y=0, max=size*size;

	square[y][x]=1;
	
	for(int i=2;i<=max;i++)
	{
		y--;
		x++;

		if(y<0)
			y+=size;
		if(x>size-1)
			x-=size;

		if(square[y][x]!=0)
		{
			y+=2;
			x--;

			if(y>size-1)
				y-=size;
			if(x<0)
				x+=size;
		}
		square[y][x]=i;
	}
}
bool squareodd::checksquare()
{
	if(size%2==0 || size<1 || size>max_size)
		return false;
}