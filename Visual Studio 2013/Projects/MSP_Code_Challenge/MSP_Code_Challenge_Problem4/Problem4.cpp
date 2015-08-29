#include <iostream>
#include <vector>
using namespace std;

class max_min
{
private:
	vector<int> v;
	int max, min;
public:
	max_min();
	int Max();
	int Min();
};
max_min::max_min() : max(0), min(0)
{
	int dummy = 0;

	cout << "¼ö ÀÔ·Â" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> dummy;
		v.push_back(dummy);
	}
}
int max_min::Max()
{
	max = v[0];

	for (int i = 0; i < 5; i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	return max;
}
int max_min::Min()
{
	min = v[0];

	for (int i = 0; i < 5; i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	return min;
}
int main()
{
	max_min m;

	cout << "ÃÖ´ñ°ª : " << m.Max() << endl;
	cout << "ÃÖ¼Ú°ª : " << m.Min() << endl;
}