#include "String.h"

String::String() : str(NULL), len(0)	{}
String::String(const char* s) : len(strlen(s) + 1)
{
	str = new char[len];
	strcpy_s(str, sizeof(char) * len, s);
}
String::String(const String& s) : len(s.len)
{
	str = new char[len];
	strcpy_s(str, sizeof(char) * len, s.str);
}
String::~String()
{
	if (str != NULL)
		delete[]str;
}

String String::operator+ (const String& s) const
{
	String temp;
	temp.len = len + s.len;
	temp.str = new char[temp.len - 1];
	strcpy_s(temp.str, sizeof(char) * len, str);
	strcat_s(temp.str, sizeof(char) * s.len, s.str);
	return temp;
}
String String::operator+= (const String& s)
{
	String temp;
	temp.len = len + s.len;
	temp.str = new char[temp.len - 1];
	strcpy_s(temp.str, sizeof(char) * len, str);
	strcat_s(temp.str, sizeof(char) * s.len, s.str);
	if (str != NULL)
		delete[]str;
	str = NULL;
	*this = temp;
	return *this;
}
String& String::operator= (const String& s)
{
	if (str != NULL)
		delete[]str;
	len = s.len;
	str = new char[len];
	strcpy_s(str, sizeof(char) * len, s.str);
	return *this;
}

bool operator== (const String& s1, const String& s2)	{ return !strcmp(s1.str, s2.str); }

ostream& operator<< (ostream& os, const String& s)
{
	os << s.str;
	return os;
}
istream& operator>> (istream& is, String& s)
{
	char string[100];
	is >> string;
	s = String(string);
	return is;
}