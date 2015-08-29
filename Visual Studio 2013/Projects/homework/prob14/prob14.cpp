//20113259	김보운
//문제-14 삼각형의 종류

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int a, int b, int c);
void sort(int a, int b, int c);

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
		int a, b, c;

		inStream>>a>>b>>c;

		sort(a, b, c);
		compute(a, b, c);
		cout<<endl;
	}
	inStream.close();
}

void compute(int a, int b, int c)
{
	if(a+b<=c)
		cout<<"0";
	else if(a==b && b==c)
		cout<<"1";
	else if((a*a)+(b*b)==(c*c))
		cout<<"2";
	else if(a==b || a==c || b==c)
		cout<<"3";
	else
		cout<<"4";
}
void sort(int a, int b, int c)
{
	int temp;

	if(a<b && b<c)
	{
		temp=c;
		c=a;
		a=temp;
	}
	else if(a<b && b>c)
	{
		temp=b;
		b=a;
		a=temp;
	}
}