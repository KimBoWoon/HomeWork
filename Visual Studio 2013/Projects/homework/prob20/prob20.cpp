//20113259	김보운
//문제-20 약수의 합

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int val);

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
		int val;

		inStream>>val;

		compute(val);
	}
	inStream.close();
}

void compute(int val)
{
	int sum=0, num=0;

	for(int i=1;i<val;i++)
	{
		if((val%i)==0)
		{
			num++;
			sum+=i;
		}
	}
	cout<<num<<" "<<sum<<endl;
}