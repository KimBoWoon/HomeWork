//20113259	김보운
//문제-12 모래시계 출력하기

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void main()
{
	ifstream inStream;
	int testnum, height, a, b, c, d, e;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		inStream>>height;
		d=e=0;
		
		for(int j=0;j<=height/2;j++)
		{
			if(j>0)
			{
				for(c=0;c<j;c++)
				{
					cout<<"-";
				}
			}
			cout<<"*";
			for(a=d;a<height/2;a++)
			{
				cout<<"+";
				for(b=0;b<1;b++)
				{
					cout<<"*";
				}
			}
			if(j>0)
			{
				for(c=0;c<j;c++)
				{
					cout<<"-";
				}
			}
			d++;
			cout<<endl;
		}
		for(int j=0;j<height/2;j++)
		{
			for(c=1+e;c<height/2;c++)
			{
					cout<<"-";
			}
			cout<<"*";
			for(a=-1+d;a<=height/2;a++)
			{
				cout<<"+";
				for(b=0;b<1;b++)
				{
					cout<<"*";
				}
			}
			for(c=1+e;c<height/2;c++)
			{
					cout<<"-";
			}
			d--;
			e++;
			cout<<endl;
		}
	}
	inStream.close();
}