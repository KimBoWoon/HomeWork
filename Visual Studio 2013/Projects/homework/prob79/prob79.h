#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class complex
{
public:
	complex(int real=0, int imag=0);
	complex(const complex& number);

	int getrealpart() const;
	int getimaginarypart() const;

	void setrealpart(int real);
	void setimainarypart(int imag);
	void set(int real, int imag);
	
	complex operator+ (const complex& number) const;
	complex operator+ (int value) const;
	complex operator- (const complex& number) const;
	complex operator- (int value) const;
	complex operator* (const complex& number) const;
	complex operator* (int value) const;
	complex operator+= (const complex& number);
	complex operator-= (const complex& number);
	complex operator*= (const complex& number);
	friend complex operator+ (int value, complex& number);
	friend complex operator- (int value, complex& number);
	friend complex operator* (int value, complex& number);

	complex& operator= (const complex& number);
	complex& operator= (int value);

	bool operator== (const complex& number) const;
	bool operator!= (const complex& number) const;
	bool operator>= (const complex& number) const;
	bool operator<= (const complex& number) const;
	bool operator> (const complex& number) const;
	bool operator< (const complex& number) const;
	friend ostream& operator<< (ostream& os, const complex& number);
	friend istream& operator>> (istream& is, complex& number);

	complex operator- ();
	complex operator~ ();
	complex operator-- ();
	complex operator-- (int);
	complex operator++ ();
	complex operator++ (int);

private:
	int realpart, imaginarypart;
	int norm() const;
};