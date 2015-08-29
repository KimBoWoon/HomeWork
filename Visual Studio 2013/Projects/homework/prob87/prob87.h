#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
using namespace std;

template <int N, typename real>
class Vector
{
public:
	template <int N, typename real>
	friend ostream& operator<< (ostream& os, const Vector<N, real>& vec);
	template <int N, typename real>
	friend Vector<N, real> operator* (real fscalar, const Vector<N, real>& vec);

	Vector();
	Vector(const real* ary);
	Vector(const Vector& vec);

	operator const real* () const;
	operator real* ();
	real operator[] (int i) const;
	real& operator[] (int i);

	Vector& operator= (const Vector& vec);
	
	bool operator== (const Vector& vec) const;
	bool operator!= (const Vector& vec) const;

	Vector operator+ (const Vector& vec) const;
	Vector operator- (const Vector& vec) const;
	Vector operator* (real fscalar) const;
	Vector operator- () const;

	Vector& operator+= (const Vector& vec);
	Vector& operator-= (const Vector& vec);
	Vector& operator*= (real fscalar);

	real squaredlength() const;
	real dot(const Vector& vec) const;

protected:
	real coord[N];
};

template <int N, typename real>
ostream& operator<< (ostream& os, const Vector<N, real>& vec)
{
	cout<<"("<<vec.coord[0];

	for(int i=1;i<N;i++)
		cout<<","<<vec.coord[i];

	cout<<")";

	return os;
}
template <int N, typename real>
Vector<N, real> operator* (real fscalar, const Vector<N, real>& vec)
{
	Vector temp;

	for(int i=0;i<N;i++)
		temp.coord[i]=fscalar*vec.coord[i];

	return temp;
}

template <int N, typename real>
Vector<N, real>::Vector()	{}
template <int N, typename real>
Vector<N, real>::Vector(const real* ary)	{	memcpy(coord, ary, N*sizeof(real));	}
template <int N, typename real>
Vector<N, real>::Vector(const Vector& vec)	{	memcpy(coord, vec.coord, N*sizeof(real));	}

template <int N, typename real>
Vector<N, real>::operator const real* () const	{	return coord;	}
template <int N, typename real>
Vector<N, real>::operator real* ()	{	return coord;	}
template <int N, typename real>
real Vector<N, real>::operator[] (int i) const
{
	assert(0<=i && i<N);
	return coord[i];
}
template <int N, typename real>
real& Vector<N, real>::operator[] (int i)
{
	assert(0<=i && i<N);
	return coord[i];
}

template <int N, typename real>
Vector<N, real>& Vector<N, real>::operator= (const Vector& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec.coord, N*sizeof(real));
	return *this;
}

template <int N, typename real>
bool Vector<N, real>::operator== (const Vector& vec) const	{	return memcmp(coord, vec.coord, N*sizeof(real))==0;	}
template <int N, typename real>
bool Vector<N, real>::operator!= (const Vector& vec) const	{	return memcmp(coord, vec.coord, N*sizeof(real))!=0;	}

template <int N, typename real>
Vector<N, real> Vector<N, real>::operator+ (const Vector& vec) const
{
	Vector<N, real> sumvec;

	for(int i=0;i<N;i++)
		sumvec.coord[i]=coord[i]+vec.coord[i];

	return sumvec;
}
template <int N, typename real>
Vector<N, real> Vector<N, real>::operator- (const Vector& vec) const
{
	Vector<N, real> miuvec;

	for(int i=0;i<N;i++)
		miuvec.coord[i]=coord[i]-vec.coord[i];

	return miuvec;
}
template <int N, typename real>
Vector<N, real> Vector<N, real>::operator* (real fscalar) const
{
	Vector<N, real> mulvec;

	for(int i=0;i<N;i++)
		mulvec.coord[i]=fscalar*coord[i];

	return mulvec;
}
template <int N, typename real>
Vector<N, real> Vector<N, real>::operator- () const
{
	for(int i=0;i<N;i++)
		coord[i]=-coord[i];

	return *this;
}

template <int N, typename real>
Vector<N, real>& Vector<N, real>::operator+= (const Vector& vec)
{
	for(int i=0;i<N;i++)
		coord[i]+=vec.coord[i];

	return *this;
}
template <int N, typename real>
Vector<N, real>& Vector<N, real>::operator-= (const Vector& vec)
{
	for(int i=0;i<N;i++)
		coord[i]-=vec.coord[i];

	return *this;
}
template <int N, typename real>
Vector<N, real>& Vector<N, real>::operator*= (real fscalar)
{
	for(int i=0;i<N;i++)
		coord[i]*=fscalar;

	return *this;
}

template <int N, typename real>
real Vector<N, real>::squaredlength() const
{
	real sum=0;

	for(int i=0;i<N;i++)
		sum+=coord[i]*coord[i];

	return sum;
}
template <int N, typename real>
real Vector<N, real>::dot(const Vector& vec) const
{
	real sum=0;

	for(int i=0;i<N;i++)
		sum+=coord[i]*vec.coord[i];

	return sum;
}