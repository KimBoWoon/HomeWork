//20113259 김보운
//문제-29 요일계산
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int zera(int year, int month, int day);

int main(void)
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input file opening failde\n";
		exit(1);
	}

	inStream>>cases;

	for(int i=0;i<cases;i++)
	{
		int year, month, day;

		inStream>>year>>month>>day;

		cout<<zera(year, month, day)<<endl;
	}
}
int zera(int year, int month, int day)
{
	if(month<=2)
	{
		year+=-1;
		month+=12;
	}

	return ((21*(year/100)/4)+(5*(year%100)/4)+(26*(month+1)/10)+day-1)%7;
}