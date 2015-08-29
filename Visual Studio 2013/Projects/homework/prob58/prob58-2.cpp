#include "prob58.h"

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream>>cases;

	readnumber numreading;

	for(int i=0;i<cases;i++)
	{
		unsigned int num;

		inStream>>num;

		numreading.setnumber(num);
		numreading.read();
	}
	inStream.close();
}