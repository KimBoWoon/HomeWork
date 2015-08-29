/*
http://blog.naver.com/choyi0521/80206821567
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "BAABABAABABAABAABABAA";
	string p = "BAABABAA";
	int *pi = new int[p.size() + 1];

	pi[0] = -1;
	for (size_t i = 0, j = -1; i < p.size();)
	{
		if (j == -1 || p[i] == p[j])
		{
			i++;
			j++;
			pi[i] = j;
		}
		else
			j = pi[j];
	}

	for (size_t i = 0; i < p.size() + 1; i++)
		(i == p.size()) ? cout << pi[i] << endl : cout << pi[i] << " ";

	for (size_t i = 0, j = 0; i < s.size();)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = pi[j];

		if (j == p.size())
		{
			cout << "패턴 발견" << endl;
			j = 0;
		}
	}
}