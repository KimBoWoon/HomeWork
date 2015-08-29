//20113259	김보운
//문제-23 패리티 비트

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

unsigned int compute(unsigned int n);

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
		int n;

		inStream>>n;

		cout<<compute(n)<<endl;
	}
	inStream.close();
}

unsigned int compute(unsigned int n)
{
	unsigned int value, parity=0;

	value=n&0xffffffff;

	for(int i=0;i<31;i++)
	{
		parity^=value&0x01;
		value>>=1;
	}
	if(parity)
		n|=0x80000000;

	return n;
}