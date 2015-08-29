#include <iostream>
using namespace std;

typedef double(*Func)(const double, const double);

static double Add(const double val1, const double val2);
static double Sub(const double val1, const double val2);
static double Mul(const double val1, const double val2);
static double Div(const double val1, const double val2);
static double Calculate(const double val1, const double val2, Func func);

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
double Calculate(const double val1, const double val2, Func func) {
	return func(val1, val2);
}
int main(int argc, char *argv[]) {
	try {
		cout << "Result = " << Calculate(40, 10, Add) << endl;
		cout << "Result = " << Calculate(40, 10, Sub) << endl;
		cout << "Result = " << Calculate(40, 10, Mul) << endl;
		cout << "Result = " << Calculate(40, 0, Div) << endl;
	}
	catch (const char *err) {
		cerr << err << endl;
	}
	return 0;
}