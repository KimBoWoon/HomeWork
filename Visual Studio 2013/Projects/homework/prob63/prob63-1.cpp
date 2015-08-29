#include "prob63.h"

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

	for(int i=0;i<cases;i++)
	{
		int size;

		inStream>>size;

		squareodd oddsquare(size);
		oddsquare.printsquare();
	}
	inStream.close();
}