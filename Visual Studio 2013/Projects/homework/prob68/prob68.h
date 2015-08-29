#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE=9;

class knighttour
{
public:
	knighttour();
	knighttour(int srow, int scol);

	bool buildknighttour(int startrow, int startcol);
	void printboard();

private:
	typedef int boardtype[MAX_SIZE][MAX_SIZE];

	bool recurknighttour(int startrow, int startcol, int move);
	bool isvalidmove(int row, int col);

	int sizerow, sizecol;
	boardtype board;
};