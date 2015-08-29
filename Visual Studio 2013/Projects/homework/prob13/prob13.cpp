//20113259	김보운
//문제-13 직선 그래프 출력하기

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

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
		int height, star, star2;
		inStream>>height;

		star=height;
		star2=height;

		for(int h=0;h<height/2;h++)
		{
			for(int j=0;j<height/2;j++)
				cout<<".";
			cout<<"I";
			for(int j=0;j<height/2;j++)
			{
				if(star/2-1==j)
				{
					cout<<"*";
					star -= 2;
				}
				else
					cout<<".";
			}
			cout<<endl;
		}
		for(int j=0;j<height/2;j++)
			cout<<"+";
		cout<<"O";
		for(int j=0;j<height/2;j++)
			cout<<"+";
		cout<<endl;
		for(int h=0;h<height/2;h++)
		{
			for(int j=0;j<height/2;j++)
			{
				if(star2/2-1==j)
				{
					cout<<"*";
					star2 -= 2;
				}
				else
					cout<<".";
			}
			cout<<"I";
			for(int j=0;j<height/2;j++)
				cout<<".";
			cout<<endl;
		}
	}
	inStream.close();
}