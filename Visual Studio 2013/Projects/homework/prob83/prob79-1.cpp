#include "prob79.h"

complex::complex(int real, int imag) : realpart(real), imaginarypart(imag)	{}
complex::complex(const complex& number) : realpart(number.realpart), imaginarypart(number.imaginarypart)	{}

int complex::getrealpart() const	{ return realpart; }
int complex::getimaginarypart() const	{ return imaginarypart; }

void complex::setrealpart(int real)	{ realpart = real; }
void complex::setimainarypart(int imag)	{ imaginarypart = imag; }
void complex::set(int real, int imag)
{
	realpart = real;
	imaginarypart = imag;
}

complex complex::operator+ (const complex& number) const
{
	int newreal = realpart + number.realpart;
	int newimag = imaginarypart + number.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator- (const complex& number) const
{
	int newreal = realpart - number.realpart;
	int newimag = imaginarypart - number.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator* (const complex& number) const
{
	int newreal = realpart*number.realpart - imaginarypart*number.imaginarypart;
	int newimag = imaginarypart*number.realpart + realpart*number.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator+ (int value) const
{
	complex temp(value);

	int newreal = realpart + temp.realpart;
	int newimag = imaginarypart + temp.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator- (int value) const
{
	complex temp(value);

	int newreal = realpart - temp.realpart;
	int newimag = imaginarypart - temp.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator* (int value) const
{
	complex temp(value);

	int newreal = realpart*temp.realpart - imaginarypart*temp.imaginarypart;
	int newimag = imaginarypart*temp.realpart + realpart*temp.imaginarypart;

	return complex(newreal, newimag);
}
complex complex::operator+= (const complex& number)
{
	realpart += number.realpart;
	imaginarypart += number.imaginarypart;

	return *this;
}
complex complex::operator-= (const complex& number)
{
	realpart -= number.realpart;
	imaginarypart -= number.imaginarypart;

	return *this;
}
complex complex::operator*= (const complex& number)
{
	int newreal = realpart*number.realpart - imaginarypart*number.imaginarypart;
	int newimag = imaginarypart*number.realpart + realpart*number.imaginarypart;

	realpart = newreal;
	imaginarypart = newimag;

	return *this;
}
complex operator+ (int value, complex& number)
{
	complex temp(value);

	int newreal = temp.realpart + number.realpart;
	int newimag = temp.imaginarypart + number.imaginarypart;

	return complex(newreal, newimag);
}
complex operator- (int value, complex& number)
{
	complex temp(value);

	int newreal = temp.realpart - number.realpart;
	int newimag = temp.imaginarypart - number.imaginarypart;

	return complex(newreal, newimag);
}
complex operator* (int value, complex& number)
{
	complex temp(value);

	int newreal = temp.realpart*number.realpart - temp.imaginarypart*number.imaginarypart;
	int newimag = temp.imaginarypart*number.realpart + temp.realpart*number.imaginarypart;

	return complex(newreal, newimag);
}

complex& complex::operator= (const complex& number)
{
	this->realpart = number.realpart;
	this->imaginarypart = number.imaginarypart;

	return *this;
}
complex& complex::operator= (int value)
{
	realpart = value;
	imaginarypart = 0;

	return *this;
}

bool complex::operator== (const complex& number) const
{
	return (realpart == number.realpart) && (imaginarypart == number.imaginarypart);
}
bool complex::operator!= (const complex& number) const
{
	return (realpart != number.realpart) || (imaginarypart != number.imaginarypart);
}
bool complex::operator>= (const complex& number) const	{ return norm() >= number.norm(); }
bool complex::operator<= (const complex& number) const	{ return norm() <= number.norm(); }
bool complex::operator> (const complex& number) const	{ return norm() > number.norm(); }
bool complex::operator< (const complex& number) const	{ return norm() < number.norm(); }

complex complex::operator- ()	{ return complex(-realpart, -imaginarypart); }
complex complex::operator~ ()	{ return complex(realpart, -imaginarypart); }
complex complex::operator-- ()
{
	realpart--;

	return *this;
}
complex complex::operator++ ()
{
	realpart++;

	return *this;
}
complex complex::operator-- (int)
{
	const complex temp(realpart, imaginarypart);

	realpart--;

	return temp;
}
complex complex::operator++ (int)
{
	const complex temp(realpart, imaginarypart);

	realpart++;

	return temp;
}

int complex::norm() const	{ return realpart*realpart + imaginarypart*imaginarypart; }

ostream& operator<< (ostream& os, const complex& number)
{
	os << "(" << number.realpart << "," << number.imaginarypart << ")";

	return os;
}
istream& operator>> (istream& is, complex& number)
{
	is >> number.realpart >> number.imaginarypart;

	return is;
}