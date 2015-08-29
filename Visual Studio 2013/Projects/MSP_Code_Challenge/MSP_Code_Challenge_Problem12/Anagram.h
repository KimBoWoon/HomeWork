#ifndef __ANAGRAM__
#define __ANAGRAM__

#include <iostream>
#include <string>
#include <cstring>
#include "Alphabet.h"
using namespace std;

class Anagram
{
private:
	Alphabet alpha;
	char str[100];
public:
	Anagram();
	bool operator== (Anagram &a);
};

#endif