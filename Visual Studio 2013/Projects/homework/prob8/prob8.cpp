//20113259	김보운
//문제-08 시간 계산

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void main()
{
	ifstream inStream;
	int H, M, S, h, m, s, val, testnum;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "input File opening failed.\n";
		exit(1);
	}

	inStream >> testnum;

	for (int i = 0; i < testnum; i++)
	{
		int day = 0, hour = 0, minute = 0, second = 0, sum = 0, sum2 = 0, sum3 = 0;
		inStream >> val;

		for (int j = 0; j < val; j++)
		{
			inStream >> H >> M >> S >> h >> m >> s;
			hour = minute = second = 0;

			for (int x = 0; x < H; x++)
				hour++;
			for (int x = 0; x < M; x++)
				minute++;
			for (int x = 0; x < S; x++)
				second++;

			hour *= 3600;
			minute *= 60;
			sum2 = hour + minute + second;
			hour = minute = second = 0;

			for (int x = 0; x < h; x++)
				hour++;
			for (int x = 0; x < m; x++)
				minute++;
			for (int x = 0; x < s; x++)
				second++;

			hour *= 3600;
			minute *= 60;
			sum3 = hour + minute + second;
			sum += abs(sum2 - sum3);
		}
		day = sum / 86400;
		hour = (sum - (day * 86400)) / 3600;
		minute = (sum - ((day * 86400) + (hour * 3600))) / 60;
		second = (sum - ((day * 86400) + (hour * 3600) + (minute * 60)));
		cout << day << ' ' << hour << ' ' << minute << ' ' << second << endl;
	}
	inStream.close();
}