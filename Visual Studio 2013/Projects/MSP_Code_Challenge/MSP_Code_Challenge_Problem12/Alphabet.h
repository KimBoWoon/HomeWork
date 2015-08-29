#ifndef __ALPHABET__
#define __ALPHABET__

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Alphabet
{
private:
	int alphabet[26];
public:
	Alphabet();
	void SetAlphabet(const char *s);
	int* GetAlphabet();
};

#endif