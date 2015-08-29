#include "prob87.h"

template <typename real>
class vector3 : public vector<3, real>
{
public:
	vector3();
	vector3(real x, real y, real z);
	vector3(const vector3& vec3);

	real x() const;
	real& x();
	real y() const;
	real& y();
	real z() const;
	real& z();

	vector3& operator= (const vector3& vec3);
	vector3& operator= (const vector& vec);

	vector3 cross(const vector3& vec3) const;
};
template <typename real>
vector3<real>::vector()	{}
template <typename real>
vector3<real>::vector(real x, real y, real z)
{
	coord[0]=x;
	coord[1]=y;
	coord[2]=z;
}
template <typename real>
vector3<real>::vector3(const vector3& vec3)	{	memcpy(coord, vec3.coord, 2*sizeof(real));	}

template <typename real>
vector3<real>::real x() const	{	return cord[0];	}
template <typename real>
vector3<real>::real& x()	{	return cord[0];	}
template <typename real>
vector3<real>::real y() const	{	return cord[1];	}
template <typename real>
vector3<real>::real& y()	{	return cord[1];	}
template <typename real>
vector3<real>::real z() const	{	return cord[2];	}
template <typename real>
vector3<real>::real& z()	{	return cord[2];	}

template <typename real>
vector3<real>& vector3<real>::operator= (const vector3& vec3)
{
	if(this==&vec3)
		return *this;

	memcpy(coord, vec3.coord, 3*sizeof(real));
	return *this;
}
template <typename real>
vector3<real>& vector3<real>::operator= (const vector& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec, 3*sizeof(real));
	return *this;
}

template <typename real>
vector3<real> vector3<real>::cross(const vector3& vec3) const
{
	return vetor3(coord[1]*vec3.coord[2]-coord[2]*vec3.coord[1], coord[2]*vec3.coord[0]-coord[0]*vec3.coord[2], coord[0]*vec3.coord[1]-coord[1]*vec3.coord[0]);
}