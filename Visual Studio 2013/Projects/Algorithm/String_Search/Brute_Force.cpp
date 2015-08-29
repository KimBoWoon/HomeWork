#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "ABCABACDC";
	string p = "BA";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == p[0])
		{
			for (int j = 1; j < p.size(); j++)
			{
				if (s[i + j] != p[j])
					break;
				else if (j == p.size() - 1)
				{
					cout << i << " 패턴 일치" << endl;
					return 0;
				}
			}
		}
	}
}