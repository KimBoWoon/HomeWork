//20113259	�躸��
//����-07 ���ڸ� ���� ����ϱ�

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void main()
{
	ifstream inStream;
	int result, mul, val, testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		inStream>>val;
		result=1;

		for(int j=0;j<val;j++)
		{
			inStream>>mul;
			result*=mul%10;
			result%=10;
		}
		std::cout<<result<<std::endl;
	}
	inStream.close();
}