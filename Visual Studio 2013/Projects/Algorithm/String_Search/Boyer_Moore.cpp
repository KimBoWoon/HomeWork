#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
	string s = "ABBABAAB";
	string p = "ABAAB";
	int BadCharacter[26];
	int* GoodSuffix = new int[p.size() + 1];

	memset(BadCharacter, -1, sizeof(int) * 26);

	for (int i = 0; i < p.size(); i++)
		BadCharacter[p[i] - 65] = i;

	for (int i = p.size() + 1; i >= 0; i--)
	{
		
	}
}