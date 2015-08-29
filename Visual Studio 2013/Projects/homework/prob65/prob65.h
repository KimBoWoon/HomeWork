#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int card_size=5;
const int num_calls=75;

class bingo
{
public:
	bingo();
	bingo(int card_num[][card_size]);

	void setcard(int card_num[][card_size]);

	int runbingogame(int numcalls[]);

private:
	int bingocard[card_size][card_size];
};