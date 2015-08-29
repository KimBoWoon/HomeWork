#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define SIZE 26
#define STRLEN 500
#define KEYLEN 100

class Vigenere
{
private:
	char vigenere[SIZE][SIZE];
	void Encryption(const char encryptionkey[KEYLEN], const char s[STRLEN]);
	void Decryption(const char encryptionkey[KEYLEN], const char s[STRLEN]);
public:
	Vigenere();
	void EncryptionOrDecryption(const char encryptionkey[KEYLEN], const char s[STRLEN], int n);
};
Vigenere::Vigenere()
{
	int cnt = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (((65 + i) + j) < 91)
				vigenere[i][j] = 65 + i + j;
			else
				vigenere[i][j] = 65 + cnt++;
		}
		cnt = 0;
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << vigenere[i][j] << " ";
		cout << endl;
	}
}
void Vigenere::Encryption(const char encryptionkey[KEYLEN], const char s[STRLEN])
{
	char *encryption, c;
	int x, y, cnt = 0, slen = strlen(s) + 1, keylen = strlen(encryptionkey) + 1;

	encryption = new char[slen];

	for (int i = 0; i < slen - 1; i++)
	{
		c = s[i];
		if ((c > 64 && c < 91) || c > 96 && c < 123)
		{
			if (c > 64 && c < 91)
			{
				x = c - 65;
				cnt = 0;
			}
			else
			{
				x = c - 97;
				cnt = 1;
			}
			c = encryptionkey[i % (keylen - 1)];
			if (c > 64 && c < 91)
				y = c - 65;
			else
				y = c - 97;
			if (cnt == 0)
				encryption[i] = vigenere[x][y];
			else
				encryption[i] = vigenere[x][y] + 32;
		}
		else if (c == '-')
			encryption[i] = '-';
		else
			encryption[i] = '.';
	}
	for (int i = 0; i < slen - 1; i++)
		cout << encryption[i];
	cout << endl;
}
void Vigenere::Decryption(const char encryptionkey[KEYLEN], const char s[STRLEN])
{
	char *encryption, c;
	int x = 0, y, cnt = 0, slen = strlen(s) + 1, keylen = strlen(encryptionkey) + 1;

	encryption = new char[slen];

	for (int i = 0; i < slen - 1; i++)
	{
		c = s[i];
		if ((c > 64 && c < 91) || (c > 96 && c < 123))
		{
			c = encryptionkey[i % (keylen - 1)];
			if (c > 64 && c < 91)
				y = c - 65;
			else
				y = c - 97;
			c = s[i];
			if (c > 64 && c < 91)
			{
				cnt = 0;
				for (int j = 0; j < 26; j++)
				{
					if (vigenere[j][y] != c)
						x++;
					else
						break;
				}
			}
			else if (c > 96 && c < 123)
			{
				cnt = 1;
				for (int j = 0; j < 26; j++)
				{
					if (vigenere[j][y] != c - 32)
						x++;
					else
						break;
				}
			}
			if (cnt == 0)
				encryption[i] = vigenere[x][0];
			else
				encryption[i] = vigenere[x][0] + 32;
		}
		else if (c == '-')
			encryption[i] = '-';
		else
			encryption[i] = '.';
		x = 0;
	}
	for (int i = 0; i < slen - 1; i++)
		cout << encryption[i];
	cout << endl;
}
void Vigenere::EncryptionOrDecryption(const char encryptionkey[KEYLEN], const char s[STRLEN], int n)
{
	if (n == 1)
		Encryption(encryptionkey, s);
	else
		Decryption(encryptionkey, s);
}
int main()
{
	Vigenere v;
	ifstream in;
	int cases, n;
	char encryptionkey[KEYLEN] = { 0 }, s[STRLEN] = { 0 };

	in.open("input.txt");
	if (in.fail())
	{
		cerr << "파일 없음" << endl;
		exit(1);
	}

	in >> cases;

	for (int i = 0; i < cases; i++)
	{
		in >> encryptionkey >> n >> s;

		v.EncryptionOrDecryption(encryptionkey, s, n);
	}
}