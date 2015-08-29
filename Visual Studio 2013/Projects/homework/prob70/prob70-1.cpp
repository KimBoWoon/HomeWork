#include "prob70.h"

const int max_length = 8;

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> cases;

	for (int i = 0; i < cases; i++)
	{
		char clock[max_length];
		int lap;

		inStream >> clock >> lap;

		digitalclock digitalclock(clock);

		for (int j = 0; j < abs(lap); j++)
		{
			if (lap > 0)
				digitalclock++;
			else
				--digitalclock;
		}
		cout << digitalclock;
	}
	inStream.close();
}