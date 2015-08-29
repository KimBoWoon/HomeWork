#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define MAX_SIZE 101

class rational
{
public:
	rational(long num=0, long den=1);
	rational(const rational& rat);

	long getnumerator() const;
	long getdenominator() const;

	rational operator+ (const rational& rat) const;
	rational operator+ (int value) const;
	rational operator- (const rational& rat) const;
	rational operator- (int value) const;
	rational operator* (const rational& rat) const;
	rational operator* (int value) const;
	rational operator/ (const rational& rat) const;
	rational operator/ (int value) const;
	rational operator+= (const rational& rat);
	rational operator-= (const rational& rat);
	rational operator*= (const rational& rat);
	rational operator/= (const rational& rat);
	friend rational operator+ (int value, rational& rat);
	friend rational operator- (int value, rational& rat);
	friend rational operator* (int value, rational& rat);
	friend rational operator/ (int value, rational& rat);

	rational& operator= (const rational& rat);
	rational& operator= (int value);

	bool operator== (const rational& rat) const;
	bool operator!= (const rational& rat) const;
	bool operator>= (const rational& rat) const;
	bool operator<= (const rational& rat) const;
	bool operator> (const rational& rat) const;
	bool operator< (const rational& rat) const;

	rational operator- ();
	rational operator-- ();
	rational operator-- (int);
	rational operator++ ();
	rational operator++ (int);

	friend ostream& operator<< (ostream& os, const rational& r);
	friend istream& operator>> (istream& is, rational& r);
private:
	long _num, _den;
	long gcd(long m, long n) const;
	void reduce();
};