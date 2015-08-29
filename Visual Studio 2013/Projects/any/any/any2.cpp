#include <iostream>
#include <cmath>
using namespace std;

void main()
{
	int i, j;
	int size;

	cin >> size;

	for (i = - (size / 2); i < size / 2 + 1; i++)
	{
		for (j = 1; j <= size; j++)
		{
			if (j > abs(i) && j <= size - abs(i))
				cout << '+';
			else
				cout << '*';
		}
		cout << endl;
	}
}