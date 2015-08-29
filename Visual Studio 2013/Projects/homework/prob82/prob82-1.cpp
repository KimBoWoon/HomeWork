#include "prob82.h"

rational::rational(long num, long den) :_num(num), _den(den)
{
	reduce();
}
rational::rational(const rational& rat)
{
	reduce();

	_num = rat._num;
	_den = rat._den;
}

long rational::getnumerator() const	{ return _num; }
long rational::getdenominator() const	{ return _den; }

rational rational::operator+ (const rational& rat) const
{
	int num = (_num*rat._den) + (_den*rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator+ (int value) const
{
	rational rat(value);

	int num = (_num*rat._den) + (_den*rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator- (const rational& rat) const
{
	int num = (_num*rat._den) - (_den*rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator- (int value) const
{
	rational rat(value);

	int num = (_num*rat._den) - (_den*rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator* (const rational& rat) const
{
	int num = (_num)*(rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator* (int value) const
{
	rational rat(value);

	int num = (_num)*(rat._num);
	int den = _den*rat._den;

	return rational(num, den);
}
rational rational::operator/ (const rational& rat) const
{
	int num = (_num)*(rat._den);
	int den = _den*rat._num;

	return rational(num, den);
}
rational rational::operator/ (int value) const
{
	rational rat(value);

	int num = _num*rat._den;
	int den = _den*rat._num;

	return rational(num, den);
}
rational rational::operator+= (const rational& rat)
{
	int num = (_num*rat._den) + (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return rational(_num, _den);
}
rational rational::operator-= (const rational& rat)
{
	int num = (_num*rat._den) - (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return rational(_num, _den);
}
rational rational::operator*= (const rational& rat)
{
	int num = (_num)*(rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return rational(_num, _den);
}
rational rational::operator/= (const rational& rat)
{
	int num = (_num)*(rat._den);
	int den = _den*rat._num;

	_num = num;
	_den = den;

	return rational(_num, _den);
}
rational operator+ (int value, rational& rat)
{
	rational temp(value);

	int num = (rat._num*temp._den) + (rat._den*temp._num);
	int den = rat._den*temp._den;

	return rational(num, den);
}
rational operator- (int value, rational& rat)
{
	rational temp(value);

	int num = (rat._num*temp._den) - (rat._den*temp._num);
	int den = rat._den*temp._den;

	return rational(num, den);
}
rational operator* (int value, rational& rat)
{
	rational temp(value);

	int num = (rat._num)*(temp._num);
	int den = rat._den*temp._den;

	return rational(num, den);
}
rational operator/ (int value, rational& rat)
{
	rational temp(value);

	int num = temp._num*rat._den;
	int den = temp._den*rat._num;

	return rational(num, den);
}

rational& rational::operator= (const rational& rat)
{
	this->_num = rat._num;
	this->_den = rat._den;

	return *this;
}
rational& rational::operator= (int value)
{
	_num = value;
	_den = 1;

	return *this;

}

bool rational::operator== (const rational& rat) const
{
	return (_num == rat._num) && (_den == rat._den);
}
bool rational::operator!= (const rational& rat) const
{
	return (_num != rat._num) || (_den != rat._den);
}
bool rational::operator>= (const rational& rat) const
{
	return (_num*rat._den) >= (_den*rat._num);
}
bool rational::operator<= (const rational& rat) const
{
	return (_num*rat._den) <= (_den*rat._num);
}
bool rational::operator> (const rational& rat) const
{
	return (_num*rat._den) > (_den*rat._num);
}
bool rational::operator< (const rational& rat) const
{
	return (_num*rat._den) < (_den*rat._num);
}
rational rational::operator- ()
{
	return rational(_num, -_den);
}
rational rational::operator-- ()
{
	rational rat(1);

	int num = (_num*rat._den) - (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return *this;
}
rational rational::operator-- (int)
{
	rational rat(1);
	rational temp(_num, _den);

	int num = (_num*rat._den) - (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return *this;
}
rational rational::operator++ ()
{
	rational rat(1);

	int num = (_num*rat._den) + (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return *this;
}
rational rational::operator++ (int)
{
	rational rat(1);
	rational temp(_num, _den);

	int num = (_num*rat._den) + (_den*rat._num);
	int den = _den*rat._den;

	_num = num;
	_den = den;

	return temp;
}
ostream& operator<< (ostream& os, const rational& r)
{
	if (r._num == 0)
		os << 0;
	else if (r._den == 1)
		os << r._num;
	else
		os << r._num << "/" << r._den;

	return os;
}
istream& operator>> (istream& is, rational& r)
{
	is >> r._num >> r._den;

	if (r._den == 0)
	{
		r._num = 0;
		r._den = 1;
	}
	r.reduce();

	return is;
}
long rational::gcd(long m, long n) const
{
	while (m != n)
	{
		if (m > n)
			m = m - n;
		else
			n = n - m;
	}
	return m;
}
void rational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;

	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn*_num, _den);
	_num /= g;
	_den /= g;
}