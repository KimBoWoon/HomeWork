//20113259	김보운
//문제-18 삼각형의 면적

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int x1, int x2, int y1, int y2, int z1, int z2);

void main()
{
	ifstream inStream;
	int testnum;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "input File opening failed.\n";
		exit(1);
	}

	inStream >> testnum;

	for (int i = 0; i < testnum; i++)
	{
		int x1, x2, y1, y2, z1, z2;

		inStream >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

		compute(x1, x2, y1, y2, z1, z2);
	}
	inStream.close();
}

void compute(int x1, int x2, int y1, int y2, int z1, int z2)
{
	int area;

	area = ((y1 - x1)*(z2 - x2) - (z1 - x1)*(y2 - x2));

	cout << abs(area) << " ";

	if (area < 0)
		cout << -1 << endl;
	else if (area>0)
		cout << 1 << endl;
	else if (area == 0)
		cout << 0 << endl;
}