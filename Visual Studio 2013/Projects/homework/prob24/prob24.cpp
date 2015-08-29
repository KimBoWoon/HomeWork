//20113259	김보운
//문제-23 시험 점수 분포

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void)
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
		int size, temp, value, count=1;

		inStream>>size;

		int* data=new int[size];

		for(int j=0;j<size;j++)
		{
			inStream>>value;

			data[j]=value;
		}
		for(int j=0;j<=size-1;j++)
		{
			for(int h=0;h<size-1;h++)
			{
				if(data[j]<data[h])
				{
					temp=data[j];
					data[j]=data[h];
					data[h]=temp;
				}
			}
		}
		for(int j=0;j<size;j++)
		{
			if(data[j]==data[j+1])
				count++;
			else
			{
				cout<<data[j]<<" "<<count<<" ";
				count=1;
			}
		}
		cout<<endl;
		delete []data;
	}
	inStream.close();
}