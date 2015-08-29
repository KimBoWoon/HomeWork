#ifndef __BETWEEN_CLASSES__
#define __BETWEEN_CLASSES__

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BetweenClasses
{
private:
	ifstream input;
	char v1[6][5];
	char v2[6][5];
	string week[5];
public:
	BetweenClasses();
	void InitTimetable(char v[6][5], ifstream &input);
	void Overlab() const;
	void Print(char v[6][5]) const;
	friend ostream& operator<< (ostream &os, BetweenClasses &bc);
};

#endif