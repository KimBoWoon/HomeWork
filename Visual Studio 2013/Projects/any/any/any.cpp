#include <iostream>
#include <cmath>
using namespace std;

double logcompute(double x, double base = 2);

int main()
{
	double x;

	cin >> x;

	cout << logcompute(x) << endl;
}
double logcompute(double x, double base)
{
	return log(x) / log(base);
}