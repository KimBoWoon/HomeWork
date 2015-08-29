#include "prob70.h"

digitalclock::digitalclock(int h, int m, bool ap) : hour(h), min(m), am_pm(ap)
{
}
digitalclock::digitalclock(char clock[])
{
	hour = ((clock[0] - 48) * 10) + (clock[1] - 48);
	min = ((clock[3] - 48) * 10) + (clock[4] - 48);

	if (clock[5] == 'P')
		am_pm = true;
	else if (clock[5] == 'A')
		am_pm = false;
}
digitalclock digitalclock::tick()
{
	++min;

	if (min == 60)
	{
		hour++;
		min = 0;
	}
	if (hour == 13)
		hour = 1;
	if (hour == 12 && min == 0)
		am_pm = !am_pm;

	return *this;
}
digitalclock digitalclock::untick()
{
	--min;

	if (min == -1)
	{
		hour--;
		min = 59;
	}
	if (hour == 0)
		hour = 12;
	if (hour == 11 && min == 59)
		am_pm = !am_pm;

	return *this;
}
digitalclock digitalclock::operator++()
{
	return tick();
}
digitalclock digitalclock::operator++(int)
{
	digitalclock c = *this;
	tick();
	return c;
}
digitalclock digitalclock ::operator-- ()
{
	return untick();
}
digitalclock digitalclock::operator-- (int)
{
	digitalclock c = *this;
	untick();
	return c;
}
ostream& operator<< (ostream& oStream, const digitalclock& c)
{
	oStream << setfill('0') << setw(2) << c.hour << ':' << setw(2) << c.min;

	if (!c.am_pm)
		oStream << "AM";
	else
		oStream << "PM";
	oStream << endl;

	return oStream;
}