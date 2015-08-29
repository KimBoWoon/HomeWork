#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class point
{
public:
	point();
	point(int coordX, int coordY);
	point(const point& p);

	int getx() const;
	int gety() const;

	void setx(int _x);
	void sety(int _y);

	bool operator== (const point& p) const;
	bool operator!= (const point& p) const;

	int dist2sqr(const point& p) const;
	int dist1(const point& p) const;

private:
	int x, y;
};