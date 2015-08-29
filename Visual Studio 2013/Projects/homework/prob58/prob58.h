#ifndef _READ_NUMBER_H_
#define _READ_NUMBER_H_

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int max_length=20;

class readnumber
{
public:
	readnumber();
	readnumber(unsigned int num);

	void setnumber(unsigned int num);

	void read() const;

private:
	unsigned int number;

	static char digits[10][max_length];
	static char teens[20][max_length];
	static char ties[10][max_length];
	static char units[4][max_length];
};

#endif