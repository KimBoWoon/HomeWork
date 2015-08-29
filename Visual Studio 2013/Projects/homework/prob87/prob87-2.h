#include "prob87.h"

template <typename real>
class Vector2 : public Vector<2, real>
{
public:
	Vector2();
	Vector2(real x, real y);
	Vector2(const Vector2& vec2);

	real x() const;
	real& x();
	real y() const;
	real& y();

	Vector2& operator= (const Vector2& vec2);
	Vector2& operator= (const Vector& vec);

	Vector2 perp() const;
};
template <typename real>
Vector2<real>::Vector2()	{}
template <typename real>
Vector2<real>::Vector2(real x, real y)
{
	coord[0]=x;
	coord[1]=y;
}
template <typename real>
Vector2<real>::Vector2(const Vector2& vec2)	{	memcpy(coord, vec2.coord, 2*sizeof(real));	}

template <typename real>
real Vector2<real>::x() const	{	return cord[0];	}
template <typename real>
real& Vector2<real>::x()	{	return cord[0];	}
template <typename real>
real Vector2<real>::y() const	{	return cord[1];	}
template <typename real>
real& Vector2<real>::y()	{	return cord[1];	}

template <typename real>
Vector2<real>& Vector2<real>::operator= (const Vector2& vec2)
{
	if(this==&vec2)
		return *this;

	memcpy(coord, vec2.coord, 2*sizeof(real));
	return *this;
}
template <typename real>
Vector2<real>& Vector2<real>::operator= (const Vector<2, real>& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec, 2*sizeof(real));
	return *this;
}

template <typename real>
Vector2<real> Vector2<real>::perp() const	{	return Vector2(coord[1], -coord[0]);	}