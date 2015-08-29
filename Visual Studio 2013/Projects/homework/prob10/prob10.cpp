//20113259	김보운
//문제-10 숫자로 삼각형 출력하기

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int height);

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
		int height;

		inStream>>height;

		compute(height);
	}
	inStream.close();
}

void compute(int height)
{
	int x=0, y=1, h=height-1, t=0;

	for(int i=0;i<height;i++)
	{
		cout<<y<<" ";
		for(int j=0;j<x;j++)
		{
			if(j==0)
			{
				cout<<y+h<<" ";
				t=y+h;
			}
			else
			{
				cout<<t+h<<" ";
				t=t+h;
			}
			h--;
		}
		cout<<endl;
		h=height-1;
		x++;
		y++;
	}
}