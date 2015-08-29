#include "prob74.h"

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
		date date1(year, month, day), date2;

		cout<<date1.getyear()<<" ";
		cout<<date1.getmonth()<<" ";
		cout<<date1.getdayofmonth()<<" "<<endl;
		cout<<date1.isleapyear()<<" ";
		cout<<date1.getdayofweek()<<" "<<endl;

		inStream>>year>>month>>day;
		date2.setdayofmonth(day);
		date2.setmonth(month);
		date2.setyear(year);

		cout<<date2.getyear()<<" ";
		cout<<date2.getmonth()<<" ";
		cout<<date2.getdayofmonth()<<" "<<endl;
		cout<<date2.isleapyear()<<" ";
		cout<<date2.getdayofweek()<<" "<<endl;

		inStream>>year>>month>>day;
		date2.setdate(year, month, day);

		cout<<date2.getyear()<<" ";
		cout<<date2.getmonth()<<" ";
		cout<<date2.getdayofmonth()<<" "<<endl;
		cout<<date2.isleapyear()<<" ";
		cout<<date2.getdayofweek()<<" "<<endl;
	}
	inStream.close();
}