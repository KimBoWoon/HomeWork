#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

class Stack_Calculator
{
private:
	stack<int> s;
	int explen;
	char exp[20];
public:
	Stack_Calculator();
	char* Getexp();
	int Operator(char op);
	int Operator(char op1, char op2);
	void Change(char *exp);
	int Calculator(char *exp);
};