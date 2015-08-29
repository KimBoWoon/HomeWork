#include "prob61.h"

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
	lifegame lifegame;

	for(int i=0;i<cases;i++)
	{
		int rows, cols, time;
		char initboard[max_size][max_size]={NULL};

		inStream>>rows>>cols>>time;

		for(int j=0;j<rows;j++)
			inStream>>initboard[j];

		lifegame.runlifegame(rows, cols, time, initboard);
	}
	inStream.close();
}