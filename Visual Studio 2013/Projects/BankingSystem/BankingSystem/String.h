#ifndef __STRING_CLASS__
#define __STRING_CLASS__

#include <iostream>
using namespace std;

class String
{
private:
	char *str;
	int len;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String operator+ (const String& s) const;
	String operator+= (const String& s);
	String& operator= (const String& s);

	friend bool operator== (const String& s1, const String& s2);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

#endif