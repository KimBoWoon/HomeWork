#include "prob68.h"

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed\n";
		exit(1);
	}

	inStream >> cases;

	for (int i = 0; i < cases; i++)
	{
		int sizerow, sizecol;
		int startrow, startcol;

		inStream >> sizerow >> sizecol;
		inStream >> startrow >> startcol;

		knighttour ktour(sizerow, sizecol);

		if (ktour.buildknighttour(startrow, startcol))
		{
			cout << 1 << endl;
			ktour.printboard();
		}
		else
			cout << 0 << endl;
	}
	inStream.close();
}