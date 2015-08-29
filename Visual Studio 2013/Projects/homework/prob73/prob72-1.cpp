#include "prob72.h"

linesegment::linesegment() : p1(0, 0), p2(0, 0)	{}
linesegment::linesegment(const point& p, const point& q) : p1(p), p2(q)	{}
linesegment::linesegment(const linesegment& seg) : p1(seg.p1), p2(seg.p2)	{}

bool linesegment::isendofsegment(const point& p) const
{
	if(p==p1 || p==p2)
		return true;
	else
		return false;
}
bool linesegment::isonsegment(const point& p) const
{
	if(iscollinear(p)==true) 
		return true;
	else 
		return false;
}
bool linesegment::properintersection(const linesegment& s) const
{
	return true;
}
bool linesegment::improperintersection(const linesegment& s) const
{
	return true;
}
int linesegment::length2sqr() const
{
	return p1.dist2sqr(p2);
}
bool linesegment::isleftside(const point& p) const
{
	return getarea2(p)>0;
}
bool linesegment::iscollinear(const point& p) const
{
	return getarea2(p)==0;
}
int linesegment::getarea2(const point& p) const
{
	int p1x, p2x, px, p1y, p2y, py;

	p1x=p1.getx();
	p1y=p1.gety();
	p2x=p2.getx();
	p2y=p2.gety();
	px=p.getx();
	py=p.gety();

	return p1x*p2y-p1y*p2x+p1y*px-p1x*py+p2x*py-px*p2y;
}