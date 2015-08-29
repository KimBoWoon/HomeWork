//20113259	김보운
//문제-03 정수연산

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int x, int y);

void main()
{
	ifstream inStream;
	int x, y, testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		inStream>>x>>y;
		compute(x, y);
	}
}

void compute(int x, int y)
{
	std::cout<<x+y<<' '<<x-y<<' '<<abs(x-y)<<' '<<x*y<<' '<<x/y<<' '<<x%y<<' ';

	if(x>y)
		std::cout<<x<<' ';
	else
		std::cout<<y<<' ';

	if(x==y)
		std::cout<<"1"<<std::endl;
	else
		std::cout<<"0"<<std::endl;
}