#include <iostream>
using namespace std;

static double Add(const double val1, const double val2);
static double Sub(const double val1, const double val2);
static double Mul(const double val1, const double val2);
static double Div(const double val1, const double val2);
static double Calculate(const double val1, const double val2, const char op);

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
	return val1 / val2;
}
double Calculate(const double val1, const double val2, const char op) {
	switch (op) {
	case '+':
		return Add(val1, val2);
	case '-':
		return Sub(val1, val2);
	case '*':
		return Mul(val1, val2);
	case '/':
		return Div(val1, val2);
	default:
		cout << "Unknow Operator" << endl;
		break;
	}

	return -999999;
}
int main(int argc, char *argv[]) {
	double re = Calculate(40, 10, '+');
	cout << "Result = " << re << endl;
	re = Calculate(40, 10, '-');
	cout << "Result = " << re << endl;
	re = Calculate(40, 10, '*');
	cout << "Result = " << re << endl;
	re = Calculate(40, 10, '/');
	cout << "Result = " << re << endl;

	return 0;
}