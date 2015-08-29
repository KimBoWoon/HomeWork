#include "prob71.h"

class linesegment
{
public:
	linesegment();
	linesegment(const point& p, const point& q);
	linesegment(const linesegment& seg);

	bool isendofsegment(const point& p) const;
	bool isonsegment(const point& p) const;
	bool properintersection(const linesegment& s) const;
	bool improperintersection(const linesegment& s) const;
	bool isleftside(const point& p) const;
	bool iscollinear(const point& p) const;

	int length2sqr() const;
private:
	point p1, p2;
	int getarea2(const point& p) const;
};