#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int max_size=101;

class lifegame
{
public:
	lifegame();

	void lifegame::runlifegame(int row, int col, int time, char gamecells[max_size][max_size]);
	void lifegame::printboard(int row, int col, char gamecells[max_size][max_size]);

private:
	char temp[max_size][max_size];
	int numalivecells;
};