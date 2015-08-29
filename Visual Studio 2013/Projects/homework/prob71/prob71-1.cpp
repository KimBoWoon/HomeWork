#include "prob71.h"

point::point() : x(0), y(0)	{}
point::point(int coordX, int coordY) : x(coordX), y(coordY)	{}
point::point(const point& p)	{}
int point::getx() const	{ return x; }
int point::gety() const	{ return y; }
void point::setx(int _x)	{ x = _x; }
void point::sety(int _y)	{ y = _y; }
bool point::operator== (const point& p) const
{
	if (x == p.x && y == p.y)
		return true;
	else
		return false;
}
bool point::operator!= (const point& p) const	{ return !operator==(p); }
int point::dist2sqr(const point& p) const	{ return ((x - p.x)*(x - p.x)) + ((y - p.y)*(y - p.y)); }
int point::dist1(const point& p) const		{ return abs(x - p.x) + abs(y - p.y); }