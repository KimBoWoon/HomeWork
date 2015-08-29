#include <iostream>
using namespace std;

static double Add(const double val1, const double val2);
static double Sub(const double val1, const double val2);
static double Mul(const double val1, const double val2);
static double Div(const double val1, const double val2);
static double Calculate(const double val1, const double val2, double(*Func)(const double, const double));

double Add(const double val1, const double val2) {
	return val1 + val2;
}
double Sub(const double val1, const double val2) {
	return val1 - val2;
}
double Mul(const double val1, const double val2) {
	return val1 * val2;
}
double Div(const double val1, const double val2) {
	if (val2 == 0)
		throw "Error Divde by zero!";
	return val1 / val2;
}
double Calculate(const double val1, const double val2, double(*Func)(const double, const double)) {
	return Func(val1, val2);
}
int main(int argc, char *argv[]) {
	double re = Calculate(40, 10, Add);
	cout << "Result = " << re << endl;

	re = Calculate(40, 10, Sub);
	cout << "Result = " << re << endl;

	re = Calculate(40, 10, Mul);
	cout << "Result = " << re << endl;

	re = Calculate(40, 10, Div);
	cout << "Result = " << re << endl;
}