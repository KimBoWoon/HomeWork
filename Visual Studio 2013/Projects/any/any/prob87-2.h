#include "prob87.h"

template <typename real>
class vector2 : public vector<2, real>
{
public:
	vector2();
	vector2(real x, real y);
	vector2(const vector2& vec2);

	real x() const;
	real& x();
	real y() const;
	real& y();

	vector2& operator= (const vector2& vec2);
	vector2& operator= (const vector& vec);

	vector2 perp() const;
};
template <typename real>
vector2<real>::vector2()	{}
template <typename real>
vector2<real>::vector2(real x, real y)
{
	coord[0]=x;
	coord[1]=y;
}
template <typename real>
vector2<real>::vector2(const vector2& vec2)	{	memcpy(coord, vec2.coord, 2*sizeof(real));	}

template <typename real>
real vector2<real>::x() const	{	return cord[0];	}
template <typename real>
real& vector2<real>::x()	{	return cord[0];	}
template <typename real>
real vector2<real>::y() const	{	return cord[1];	}
template <typename real>
real& vector2<real>::y()	{	return cord[1];	}

template <typename real>
vector2<real>& vector2<real>::operator= (const vector2& vec2)
{
	if(this==&vec2)
		return *this;

	memcpy(coord, vec2.coord, 2*sizeof(real));
	return *this;
}
template <typename real>
vector2<real>& vector2<real>::operator= (const vector<2, real>& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec, 2*sizeof(real));
	return *this;
}

template <typename real>
vector2<real> vector2<real>::perp() const	{	return vector2(coord[1], -coord[0]);	}