#include <iostream>
#include <string>
using namespace std;

class Char
{
private:
	int k;
	string str, str2;
public:
	Char()
	{
		cin >> k >> str;
	}
	void Change()
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] - (3 * (i + 1) + k) >= 65 && str[i] - (3 * (i + 1) + k) <= 90)
				str2.push_back(str[i] - (3 * (i + 1) + k));
			else
			{
				if (str[i] - (3 * (i + 1) + k) < 65)
					str2.push_back(91 - ((3 * (i + 1) + k) - (str[i] - 'A')));
				else if (str[i] - (3 * (i + 1) + k) > 90)
					str2.push_back(64 - ((3 * (i + 1) + k) - (str[i] - 'Z')));
			}
		}
	}
	void PrintString() const
	{
		cout << str2 << endl;
	}
};
int main()
{
	Char Char;

	Char.Change();

	Char.PrintString();
}