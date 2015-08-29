#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int Hash(string p, int PSize, int i = 0, int BeforeHash = 0);
bool Matching(string p, string s, int i);

int main()
{
	string s = "ABACCEFABADD";
	string p = "CCEFA";
	int PHash = 0, SHash = 0;

	PHash = Hash(p, p.size());

	for (int i = 0; i < s.size() - p.size(); i++)
	{
		SHash = Hash(s, p.size(), i, SHash);

		if (PHash == SHash)
		{
			if (Matching(p, s, i))
				cout << "패턴 발견" << endl;
			else
				cout << "패턴이 없다" << endl;
		}
	}
}
int Hash(string p, int PSize, int i, int BeforeHash)
{
	int result = 0;

	if (i == 0)
	{
		for (int i = 0; i < PSize; i++)
			result += p[i] * pow(2, PSize - (i + 1));
	}
	else
		result = 2 * (BeforeHash - p[i - 1] * pow(2, PSize - 1)) + p[i + PSize - 1];

	return result % 2147483647;
}
bool Matching(string p, string s, int i)
{
	for (int cnt = 0; i < s.size() - p.size(); i++)
	{
		if (s[i] != p[cnt++])
			return false;
	}
	return true;
}