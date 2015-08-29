#include "prob75.h"

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
int date::getdayofweek(int year, int month, int day) const
{
	if(month<=2)
	{
		year--;
		month+=12;
	}

	return ((21*(year/100)/4)+(5*(year%100)/4)+(26*(month+1)/10)+day-1)%7;
}
int date::getdayofyear() const
{
	int sum=0, dayofyear[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for(int i=1;i<month;i++)
	{
		if(i==2)
			sum+=dayofyear[i-1]+isleapyear();
		else
			sum+=dayofyear[i-1];
	}
	sum+=day;

	return sum;
}
int date::getnumholidays() const
{
	int days=1, zera, holidays=0;

	for(int i=1;i<=12;i++)
	{
		zera=getdayofweek(year, i, 1);

		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			for(int j=1;j<=31;j++)
			{
				if((i==1 && j==1))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==3 && j==1))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==5 && j==5))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==5 && j==15))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==7 && j==17))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==8 && j==15))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==10 && j==3))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==12 && j==25))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				if(zera==0 || zera==6)
					holidays++;
				zera++;
				if(zera>6)
					zera=0;
			}
			break;
		case 2:
			for(int j=1;j<=28+isleapyear();j++)
			{
				if((i==2 && (j==1 || j==2 || j==3)))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				if(zera==0 || zera==6)
					holidays++;
				zera++;
				if(zera>6)
					zera=0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			for(int j=1;j<=30;j++)
			{
				if((i==6 && j==6))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				else if((i==9 && (j==15 || j==16 || j==17)))
				{
					if(zera!=0 && zera!=6)
						holidays++;
				}
				if(zera==0 || zera==6)
					holidays++;
				zera++;
				if(zera>6)
					zera=0;
			}
			break;
		}
	}
	return holidays;
}