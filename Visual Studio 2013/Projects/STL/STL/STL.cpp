#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Ascending
{
public:
	bool operator() (int x, int y)
	{
		return x < y;
	}
};
int main()
{
	vector<int> v;
	Ascending a;

	v.push_back(40);
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);

	sort(v.begin(), v.end(), a);

	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}