#include "prob73.h"

triangle::triangle() : p1(0, 0), p2(0, 0), p3(0, 0)	{}
triangle::triangle(const point& a, const point& b, const point& c) : p1(a), p2(b), p3(c)
{
	linesegment s(p1, p2);

	if(!s.isleftside(p3))
	{
		point p;

		p=p1;
		p1=p3;
		p3=p;
	}
}
triangle::triangle(const triangle& t) : p1(t.p1), p2(t.p2), p3(t.p3)	{}
bool triangle::isinside(const point& p) const
{
	linesegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
	
	if(s1.isleftside(p)&& s2.isleftside(p) && s3.isleftside(p))
		return true;
	else
		return false;
}
bool triangle::isonboundary(const point& p) const
{
	linesegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
	
	if(s1.isonsegment(p) ==1 || s2.isonsegment(p)==1 || s3.isonsegment(p)==1)
		return true;
	else return false;
}
bool triangle::isoutside(const point& p) const
{
	if(isinside(p) || isonboundary(p))
		return false;
	else
		return true;
}
int triangle::getarea2() const
{
	return abs(area2());
}
triangle::triangletype1 triangle::gettype1() const
{
	triangletype1 type;
	int a, b, c, temp;

	a=p1.dist2sqr(p2);
	b=p2.dist2sqr(p3);
	c=p3.dist2sqr(p1);

	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=c;
		c=a;
		a=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}

	if(getarea2()==0)
		type=NOT_A_TRIANGLE;
	else if(a+b==c)
		type=RIGHT_TRIANGLE;
	else if(a+b<c)
		type=OBTUSE_TRIANGLE;
	else if(a+b>c)
		type=ACUTE_TRIANGLE;

	return type;
}
triangle::triangletype2 triangle::gettype2() const
{
	triangletype2 type;

	double a, b, c, temp;

	a=p1.dist2sqr(p2);
	b=p2.dist2sqr(p3);
	c=p3.dist2sqr(p1);

	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=c;
		c=a;
		a=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}

	if(getarea2()==0)
		type=NONTRIANGLE;
	else if(sqrt(a)+sqrt(b)<=sqrt(c))
		type=NONTRIANGLE;
	else if(sqrt(a)==sqrt(b) && sqrt(b)==sqrt(c))
		type=EQUILATERAL;
	else if(a+b==c)
		type=RIGHTTRIANGLE;
	else if(a==b || b==c || c==a)
		type=ISOSCELES;
	else
		type=SCALENE;

	return type;
}
int triangle::area2() const
{
	int p1x, p2x, p3x, p1y, p2y, p3y;

	p1x=p1.getx();
	p1y=p1.gety();
	p2x=p2.getx();
	p2y=p2.gety();
	p3x=p3.getx();
	p3y=p3.gety();

	return p1x*p2y-p1y*p2x+p1y*p3x-p1x*p3y+p2x*p3y-p3x*p2y;
}