#include "prob72.h"

linesegment::linesegment() : p1(0, 0), p2(0, 0)	{}
linesegment::linesegment(const point& p, const point& q) : p1(p), p2(q)	{}
linesegment::linesegment(const linesegment& seg) : p1(seg.p1), p2(seg.p2)	{}

bool linesegment::isendofsegment(const point& p) const
{
	if (p == p1 || p == p2)
		return true;
	else
		return false;
}
bool linesegment::isonsegment(const point& p) const
{
	if ((p.getx() > p1.getx() && p.getx() < p2.getx()) && (p.gety() > p1.gety() && p.gety() < p2.gety()))
		return true;
	else
		return false;
}
bool linesegment::properintersection(const linesegment& s) const
{
	int cross1, cross2, cross3, cross4;
	/*f(p,q,r) = r이 p~q의 선분의 오른쪽에 있으면 양의값, 왼쪽은 음의값
	　 = (p.x * q.y + q.x * r.y + r.x * p.y) - (p.y * q.x + q.y * r.x + r.y * p.x)
	  이라 할때
	  즉, f(A1,A2,B1) * f(A1,A2,B2) <=0 && f(B1,B2,A1) * f(B1,B2,A2)<=0*/

	cross1 = (p1.getx()*p2.gety() + p2.getx()*s.p1.gety() + s.p1.getx()*p1.gety()) - (p1.gety()*p2.getx() + p2.gety()*s.p1.getx() + s.p1.gety()*p1.getx());
	cross2 = (p1.getx()*p2.gety() + p2.getx()*s.p2.gety() + s.p2.getx()*p1.gety()) - (p1.gety()*p2.getx() + p2.gety()*s.p2.getx() + s.p2.gety()*p1.getx());
	cross3 = (s.p1.getx()*s.p2.gety() + s.p2.getx()*p1.gety() + p1.getx()*s.p1.gety()) - (s.p1.gety()*s.p2.getx() + s.p2.gety()*p1.getx() + p1.gety()*s.p1.getx());
	cross4 = (s.p1.getx()*s.p2.gety() + s.p2.getx()*p2.gety() + p2.getx()*s.p1.gety()) - (s.p1.gety()*s.p2.getx() + s.p2.gety()*p2.getx() + p2.gety()*s.p1.getx());

	if (cross1*cross2 < 0 && cross3*cross4 < 0)
		return true;
	else
		return false;
}
bool linesegment::improperintersection(const linesegment& s) const
{
	if (isonsegment(s.p1) || isonsegment(s.p2) || isendofsegment(s.p1) || isendofsegment(s.p2))
		return true;
	else
		return false;
}
int linesegment::length2sqr() const
{
	return p1.dist2sqr(p2);
}
bool linesegment::isleftside(const point& p) const
{
	return getarea2(p) > 0;
}
bool linesegment::iscollinear(const point& p) const
{
	return getarea2(p) == 0;
}
int linesegment::getarea2(const point& p) const
{
	int p1x, p2x, px, p1y, p2y, py;

	p1x = p1.getx();
	p1y = p1.gety();
	p2x = p2.getx();
	p2y = p2.gety();
	px = p.getx();
	py = p.gety();

	return p1x*p2y - p1y*p2x + p1y*px - p1x*py + p2x*py - px*p2y;
}