#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x = 0;
	double y = 0;

	x = round(1023 * (0.5 - (-1.0)) / 2.0);
	y = round(767 * (0.5 - (1.0)) / -2.0);

	cout << "x : " << x << ", y : " << y << endl;

	x = round(1023 * ((0.5) + 1.0) * 0.5);
	y = round(767 * ((0.5) - 1.0) * -0.5);

	cout << "x : " << x << ", y : " << y << endl;
}