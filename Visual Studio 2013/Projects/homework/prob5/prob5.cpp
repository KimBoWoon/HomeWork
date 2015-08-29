//20113259	김보운
//문제-04 두 정수 사이의 모든 정수의 합 구하기

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int num, int num2);

void main()
{
	ifstream inStream;
	int num, num2, testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		inStream>>num>>num2;
		compute(num, num2);
	}

	inStream.close();
}

void compute(int num, int num2)
{
	int result=0;

	for(;num<=num2;num++)
		result+=num;

	std::cout<<result<<std::endl;
}