//20113259	김보운
//문제-16 사각형과 점과의 거리

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int dist1(int x1, int y1, int x2, int y2, int px, int py);
int dist2(int x1, int y1, int x2, int y2, int px, int py);
int inside(int x1, int y1, int x2, int y2, int px, int py);
int onedge(int x1, int y1, int x2, int y2, int px, int py);
int segment(int a, int b, int c);

int main(void)
{
	ifstream inStream;
	int testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		int x1, y1, x2, y2, px, py;

		inStream>>x1>>y1>>x2>>y2>>px>>py;

		if(inside(x1, y1, x2, y2, px, py) || onedge(x1, y1, x2, y2, px, py))
			cout<<"0 0"<<endl;
		else
			cout<<dist1(x1, y1, x2, y2, px, py)<<" "<<dist2(x1, y1, x2, y2, px, py)<<endl;
	}
	inStream.close();
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
int dist1(int x1, int y1, int x2, int y2, int px, int py)
{
	if(segment(y1, y2 ,py))
	{
		if(px<x1)
			return (px-x1)*(px-x1);
		else if(px>x2)
			return (px-x2)*(px-x2);
	}
	else if(segment(x1, x2, px))
	{
		if(py<y1)
			return (py-y1)*(py-y1);
		else if(py>y2)
			return (py-y2)*(py-y2);
	}
	else if(py>y2)
	{
		if(px<x1)
			return (px-x1)*(px-x1)+(py-y2)*(py-y2);
		else if(px>x2)
			return (px-x2)*(px-x2)+(py-y2)*(py-y2);
	}
	else if(py<y1)
	{
		if(px<x1)
			return (px-x1)*(px-x1)+(py-y1)*(py-y1);
		else if(px>x2)
			return (px-x2)*(px-x2)+(py-y1)*(py-y1);
	}
	else
		return 0;
}
int dist2(int x1, int y1, int x2, int y2, int px, int py)
{
	if(segment(y1, y2 ,py)) 
	{
		if(px<x1)
			return abs(px-x1);
		else if(px>x2)
			return abs(px-x2);
	}
	else if(segment(x1, x2, px))
	{
		if(py<y1)
			return abs(py-y1);
		else if(py>y2)
			return abs(py-y2);
	}
	else if(py>y2)
	{
		if(px<x1)
			return abs(px-x1)+abs(py-y2);
		else if(px>x2)
			return abs(px-x2)+abs(py-y2);
	}
	else if(py<y1)
	{
		if(px<x1)
			return abs(px-x1)+abs(py-y1);
		else if(px>x2)
			return abs(px-x2)+abs(py-y1);
	}
	else
		return 0;
}
int segment(int a, int b, int c)
{
	if(c>=a && c<=b)
		return 1;
	else
		return 0;
}