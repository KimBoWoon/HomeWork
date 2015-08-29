#include <iostream>
using namespace std;

class Exception {
private:
public:
	virtual void exceptionMassage() = 0;
};
class ArithmeticException : public Exception {
private:
public:
	virtual void exceptionMassage();
};
void ArithmeticException::exceptionMassage() {
	cout << "Arithmetic Exception" << endl;
}
class DivideException : public ArithmeticException {
private:
public:
	virtual void exceptionMassage();
};
void DivideException::exceptionMassage() {
	cout << "Divide Exception" << endl;
}
int main() {
	try {
		double n = 0;
		double m = 0;

		if (n != 0 && m == 0)
			throw new DivideException();
		if (n == 0 && m == 0)
			throw new ArithmeticException();

		cout << n / m << endl;
	}
	catch (Exception* e) {
		e->exceptionMassage();
	}
}