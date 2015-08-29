//20113259	�躸��
//����-06 �־��� ������ �ִ�, �ּ� ���ϱ�

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void main()
{
	ifstream inStream;
	int num, testnum;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "input File opening failed.\n";
		exit(1);
	}

	inStream >> testnum;

	for (int i = 0; i < testnum; i++)
	{
		int max, min, val;

		inStream >> num;

		inStream >> val;
		min = max = val;

		for (int j = 1; j < num; j++)
		{
			inStream >> val;

			max < val ? max = val : max;
			min > val ? min = val : min;
		}

		std::cout << max << " " << min << std::endl;
	}

	inStream.close();
}