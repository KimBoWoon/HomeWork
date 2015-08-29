//20113259	김보운
//문제-15 삼각형의 종류(2)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

int compute(float x1, float x2, float y1, float y2, float z1, float z2);

void main()
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
		float x1, x2, y1, y2, z1, z2;

		inStream>>x1>>x2>>y1>>y2>>z1>>z2;

		cout<<compute(x1, x2, y1, y2, z1, z2)<<endl;
	}
	inStream.close();
}

int compute(float x1, float x2, float y1, float y2, float z1, float z2)
{
	float a, b, c, x, y, z, temp;

	a=((x1-y1)*(x1-y1))+((x2-y2)*(x2-y2));
	b=((x1-z1)*(x1-z1))+((x2-z2)*(x2-z2));
	c=((z1-y1)*(z1-y1))+((z2-y2)*(z2-y2));
	
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
	x=sqrt(a);
	y=sqrt(b);
	z=sqrt(c);

	if(x+y<=z)
		return 0;
	else if(a+b==c)
		return 1;
	else if(a+b<c)
		return 2;
	else if(a+b>c)
		return 3;
}