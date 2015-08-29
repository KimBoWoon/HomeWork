#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
using namespace std;

template <int N, typename real>
class vector
{
public:
	template <int N, typename real>
	friend ostream& operator<< (ostream& os, const vector<N, real>& vec);
	friend vector<N, real> operator* (real fscalar, const vector<N, real>& vec);

	vector();
	vector(const real* ary);
	vector(const vector& vec);

	operator const real* () const;
	operator real* ();
	real operator[] (int i) const;
	real& operator[] (int i);

	vector& operator= (const vector& vec);
	
	bool operator== (const vector& vec) const;
	bool operator!= (const vector& vec) const;

	vector operator+ (const vector& vec) const;
	vector operator- (const vector& vec) const;
	vector operator* (real fscalar) const;
	vector operator- () const;

	vector& operator+= (const vector& vec);
	vector& operator-= (const vector& vec);
	vector& operator*= (real fscalar);

	real squaredlength() const;
	real dot(const vector& vec) const;

protected:
	real coord[N];
};

template <int N, typename real>
ostream& operator<< (ostream& os, const vector<N, real>& vec)
{
	cout<<"("<<vec.coord[0];

	for(int i=1;i<N;i++)
		cout<<","<<vec.coord[i];

	cout<<")";

	return os;
}
template <int N, typename real>
vector<N, real> operator* (real fscalar, const vector<N, real>& vec)
{
	vector temp;

	for(int i=0;i<N;i++)
		temp.coord[i]=fscalar*vec.coord[i];

	return temp;
}

template <int N, typename real>
vector<N, real>::vector()	{}
template <int N, typename real>
vector<N, real>::vector(const real* ary)	{	memcpy(coord, ary, N*sizeof(real));	}
template <int N, typename real>
vector<N, real>::vector(const vector& vec)	{	memcpy(coord, vec.coord, N*sizeof(real));	}

template <int N, typename real>
vector<N, real>::operator const real* () const	{	return coord;	}
template <int N, typename real>
vector<N, real>::operator real* ()	{	return coord;	}
template <int N, typename real>
real vector<N, real>::operator[] (int i) const
{
	assert(0<=i && i<N);
	return coord[i];
}
template <int N, typename real>
real& vector<N, real>::operator[] (int i)
{
	assert(0<=i && i<N);
	return coord[i];
}

template <int N, typename real>
vector<N, real>& vector<N, real>::operator= (const vector& vec)
{
	if(this==&vec)
		return *this;

	memcpy(coord, vec.coord, N*sizeof(real));
	return *this;
}

template <int N, typename real>
bool vector<N, real>::operator== (const vector& vec) const	{	return memcmp(coord, vec.coord, N*sizeof(real))==0;	}
template <int N, typename real>
bool vector<N, real>::operator!= (const vector& vec) const	{	return memcmp(coord, vec.coord, N*sizeof(real))!=0;	}

template <int N, typename real>
vector<N, real> vector<N, real>::operator+ (const vector& vec) const
{
	vector<N, real> sumvec;

	for(int i=0;i<N;i++)
		sumvec.coord[i]=coord[i]+vec.coord[i];

	return sumvec;
}
template <int N, typename real>
vector<N, real> vector<N, real>::operator- (const vector& vec) const
{
	vector<N, real> miuvec;

	for(int i=0;i<N;i++)
		miuvec.coord[i]=coord[i]-vec.coord[i];

	return miuvec;
}
template <int N, typename real>
vector<N, real> vector<N, real>::operator* (real fscalar) const
{
	for(int i=0;i<N;i++)
		coord[i]*=fscalar;

	return *this;
}
template <int N, typename real>
vector<N, real> vector<N, real>::operator- () const
{
	for(int i=0;i<N;i++)
		coord[i]=-coord[i];

	return *this;
}

template <int N, typename real>
vector<N, real>& vector<N, real>::operator+= (const vector& vec)
{
	for(int i=0;i<N;i++)
		coord[i]+=vec.coord[i];

	return *this;
}
template <int N, typename real>
vector<N, real>& vector<N, real>::operator-= (const vector& vec)
{
	for(int i=0;i<N;i++)
		coord[i]-=vec.coord[i];

	return *this;
}
template <int N, typename real>
vector<N, real>& vector<N, real>::operator*= (real fscalar)
{
	for(int i=0;i<N;i++)
		coord[i]*=vec.coord[i];

	return *this;
}

template <int N, typename real>
real vector<N, real>::squaredlength() const
{
	real sum=0;

	for(int i=0;i<N;i++)
		sum=coord[i]*coord[i];

	return sqrt(sum);
}
template <int N, typename real>
real vector<N, real>::dot(const vector& vec) const
{
	real sum=0;

	for(int i=0;i<N;i++)
		sum+=coord[i]*vec.coord[i];

	return sum;
}