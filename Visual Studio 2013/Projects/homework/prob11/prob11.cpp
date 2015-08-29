//20113259	김보운
//문제-11 다이아몬드 모양 출력하기

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void main(void)
{
	ifstream inStream;
	int testnum, height, a, b, c, d;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=1;i<=testnum;i++)
	{
		inStream>>height;
		c=d=1;

		for(int j=1;j<=height/2;j++)
		{
			for(a=d;a<=height/2;a++)
				cout<<"*";
			for(b=1;b<=c;b++)
				cout<<"+";
			for(a=d;a<=height/2;a++)
				cout<<"*";
			cout<<endl;
			c+=2;
			d++;
		}
		for(int j=0;j<=height/2;j++)
		{
			for(a=d;a<=height/2;a++)
				cout<<"*";
			for(b=1;b<=c;b++)
				cout<<"+";
			for(a=d;a<=height/2;a++)
				cout<<"*";
			cout<<endl;
			c-=2;
			d--;
		}
	}
	inStream.close();
}