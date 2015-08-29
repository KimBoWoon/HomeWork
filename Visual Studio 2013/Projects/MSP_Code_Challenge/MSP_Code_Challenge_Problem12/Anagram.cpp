#include "Anagram.h"

Anagram::Anagram()
{
	cin.getline(str, 100);
	alpha.SetAlphabet(str);
}
bool Anagram::operator== (Anagram &a)
{
	for (int i = 0; i < 26; i++)
	{
		if (alpha.GetAlphabet()[i] != a.alpha.GetAlphabet()[i])
			return false;
	}
	return true;
}