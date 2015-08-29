#include "prob87-2.h"

template <typename real>
class Vector3 : public Vector<3, real>
{
public:
	Vector3();
	Vector3(real x, real y, real z);
	Vector3(const Vector3& vec3);

	real X() const;
	real& X();
	real Y() const;
	real& Y();
	real Z() const;
	real& Z();

	Vector3& operator= (const Vector3& vec3);
	Vector3& operator= (const Vector& vec);

	Vector3 cross(const Vector3& vec3) const;
};

template <typename real>
Vector3<real>::Vector3()	{}
template <typename real>
Vector3<real>::Vector3(real x, real y, real z)
{
	coord[0]=x;
	coord[1]=y;
	coord[2]=z;
}
template <typename real>
Vector3<real>::Vector3(const Vector3& vec3)	{	memcpy(coord, vec3.coord, 2*sizeof(real));	}


template <typename real>
real Vector3<real>::X() const	{	return cord[0];	}
template <typename real>
real& Vector3<real>::X()	{	return cord[0];	}
template <typename real>
real Vector3<real>::Y() const	{	return cord[1];	}
template <typename real>
real& Vector3<real>::Y()	{	return cord[1];	}
template <typename real>
real Vector3<real>::Z() const	{	return cord[2];	}
template <typename real>
real& Vector3<real>::Z()	{	return cord[2];	}

template <typename real>
Vector3<real>& Vector3<real>::operator= (const Vector3& vec3)
{
	if(this==&vec3)
		return *this;

	memcpy(coord, vec3.coord, 3*sizeof(real));
	return *this;
}
template <typename real>
Vector3<real>& Vector3<real>::operator= (const Vector& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec, 3*sizeof(real));
	return *this;
}

template <typename real>
Vector3<real> Vector3<real>::cross(const Vector3& vec3) const
{
	return Vector3(coord[1]*vec3.coord[2]-coord[2]*vec3.coord[1], coord[2]*vec3.coord[0]-coord[0]*vec3.coord[2], coord[0]*vec3.coord[1]-coord[1]*vec3.coord[0]);
}