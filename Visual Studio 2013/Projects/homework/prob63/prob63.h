#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int max_size=49;

class squareodd
{
public:
	squareodd();
	squareodd(int n);

	void printsquare() const;

private:
	int square[max_size][max_size];
	int size;
	void makesquare();
	bool checksquare();
};