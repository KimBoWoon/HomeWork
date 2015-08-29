#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class digitalclock
{
public:
	friend ostream& operator<< (ostream& oStream, const digitalclock& c);

	digitalclock(int h = 12, int m = 0, bool ap = false);
	digitalclock(char clock[]);

	digitalclock tick();
	digitalclock untick();
	digitalclock operator++();
	digitalclock operator++(int);
	digitalclock operator--();
	digitalclock operator--(int);

private:
	int hour;
	int min;
	bool am_pm;
};