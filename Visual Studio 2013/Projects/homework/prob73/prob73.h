#include "prob72.h"

class triangle
{
public:
   typedef enum triangletype1 {NOT_A_TRIANGLE=0, RIGHT_TRIANGLE, OBTUSE_TRIANGLE, ACUTE_TRIANGLE};
   typedef enum triangletype2 {NONTRIANGLE=0, EQUILATERAL, RIGHTTRIANGLE, ISOSCELES, SCALENE};

   triangle();
   triangle(const point& a, const point& b, const point& c);
   triangle(const triangle& t);

   bool isinside(const point& p) const;
   bool isonboundary(const point& p) const;
   bool isoutside(const point& p) const;

   int getarea2() const;
   triangletype1 gettype1() const;
   triangletype2 gettype2() const;

private:
   point p1, p2, p3;
   int area2() const;
};