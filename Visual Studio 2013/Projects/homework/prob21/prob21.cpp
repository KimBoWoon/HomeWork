//20113259	�躸��
//����-21 �Ҽ�

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
	int i;

	for(i=2;i<val;i++)
	{
		if(val%i==0)
		{
			cout<<0<<endl;
			break;
		}
	}
	if(i==val)
		cout<<1<<endl;
}