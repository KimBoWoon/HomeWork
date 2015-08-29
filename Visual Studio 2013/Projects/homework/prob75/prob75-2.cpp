#include "prob75.h"

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
		int year, month, day;

		inStream>>year>>month>>day;
		date date(year, month, day);

		cout<<date.getdayofyear()<<" "<<date.getnumholidays()<<endl;
	}
	inStream.close();
}