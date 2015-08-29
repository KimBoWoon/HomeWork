#include "Alphabet.h"

Alphabet::Alphabet()
{
	for (int i = 0; i < 26; i++)
		alphabet[i] = 0;
}
void Alphabet::SetAlphabet(const char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'a' || s[i] == 'A')
			alphabet[0]++;
		else if (s[i] == 'b' || s[i] == 'B')
			alphabet[1]++;
		else if (s[i] == 'c' || s[i] == 'C')
			alphabet[2]++;
		else if (s[i] == 'd' || s[i] == 'D')
			alphabet[3]++;
		else if (s[i] == 'e' || s[i] == 'E')
			alphabet[4]++;
		else if (s[i] == 'f' || s[i] == 'F')
			alphabet[5]++;
		else if (s[i] == 'g' || s[i] == 'G')
			alphabet[6]++;
		else if (s[i] == 'h' || s[i] == 'H')
			alphabet[7]++;
		else if (s[i] == 'i' || s[i] == 'I')
			alphabet[8]++;
		else if (s[i] == 'j' || s[i] == 'J')
			alphabet[9]++;
		else if (s[i] == 'k' || s[i] == 'K')
			alphabet[10]++;
		else if (s[i] == 'l' || s[i] == 'L')
			alphabet[11]++;
		else if (s[i] == 'm' || s[i] == 'M')
			alphabet[12]++;
		else if (s[i] == 'n' || s[i] == 'N')
			alphabet[13]++;
		else if (s[i] == 'o' || s[i] == 'O')
			alphabet[14]++;
		else if (s[i] == 'p' || s[i] == 'P')
			alphabet[15]++;
		else if (s[i] == 'q' || s[i] == 'Q')
			alphabet[16]++;
		else if (s[i] == 'r' || s[i] == 'R')
			alphabet[17]++;
		else if (s[i] == 's' || s[i] == 'S')
			alphabet[18]++;
		else if (s[i] == 't' || s[i] == 'T')
			alphabet[19]++;
		else if (s[i] == 'u' || s[i] == 'U')
			alphabet[20]++;
		else if (s[i] == 'v' || s[i] == 'V')
			alphabet[21]++;
		else if (s[i] == 'w' || s[i] == 'W')
			alphabet[22]++;
		else if (s[i] == 'x' || s[i] == 'X')
			alphabet[23]++;
		else if (s[i] == 'y' || s[i] == 'Y')
			alphabet[24]++;
		else if (s[i] == 'z' || s[i] == 'Z')
			alphabet[25]++;
	}
}
int* Alphabet::GetAlphabet()
{
	return alphabet;
}