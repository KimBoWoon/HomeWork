#include "prob74.h"

date::date(int _year, int _month, int _day) : year(_year), month(_month), day(_day)	{}

int date::getdayofmonth() const	{	return day;	}
int date::getmonth() const	{	return month;	}
int date::getyear() const	{	return year;	}

void date::setdayofmonth(int _day)	{	day=_day;	}
void date::setmonth(int _month)	{	month=_month;	}
void date::setyear(int _year)	{	year=_year;	}
void date::setdate(int _year, int _month, int _day)
{
	year=_year;
	month=_month;
	day=_day;
}

bool date::isleapyear() const	{	return year%4==0 && year%100!=0 || year%400==0;	}
int date::getdayofweek()
{
	if(month<=2)
	{
		year+=-1;
		month+=12;
	}

	return ((21*(year/100)/4)+(5*(year%100)/4)+(26*(month+1)/10)+day-1)%7;
}