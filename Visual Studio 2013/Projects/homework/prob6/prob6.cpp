//20113259	김보운
//문제-06 주어진 정수의 최대, 최소 구하기

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