#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class date
{
public:
	date(int _year=1582, int _month=1, int _day=1);

	int getdayofmonth() const;
	int getmonth() const;
	int getyear() const;

	void setdayofmonth(int _day);
	void setmonth(int _month);
	void setyear(int _year);
	void setdate(int _year, int _month, int _day);

	bool isleapyear() const;
	int getdayofweek();
private:
	int year, month, day;
};