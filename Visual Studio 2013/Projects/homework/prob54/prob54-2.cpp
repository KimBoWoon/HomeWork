#include "prob54.h"

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
		unsigned int num, address[4], shift = 24;
		char dummy;
		int type;

		inStream >> type;

		if (type == 1)
		{

			inStream >> address[0] >> dummy >> address[1] >> dummy >> address[2] >> dummy >> address[3];

			IPV4 ipv4(address);
			ipv4.printNumber();
		}
		else if (type == 2)
		{
			inStream >> num;

			IPV4 ipv4(num);
			ipv4.printAddress();
		}
	}
	inStream.close();
}