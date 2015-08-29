#include "Stack_Calculator.h"

Stack_Calculator::Stack_Calculator()
{
	exp[20] = { NULL };

	cout << "중위 표기식 : ";

	cin >> exp;

	explen = strlen(exp);
}
char* Stack_Calculator::Getexp()	{	return exp;	}
int Stack_Calculator::Operator(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	}

	return -1;
}
int Stack_Calculator::Operator(char op1, char op2)
{
	int op1prec = Operator(op1);
	int op2prec = Operator(op2);

	if (op1prec > op2prec)
		return 1;
	else if (op1prec < op2prec)
		return -1;
	else
		return 0;
}
void Stack_Calculator::Change(char *exp)
{
	char *Changeexp = new char[explen + 1];

	int idx = 0;
	char tok;

	memset(Changeexp, 0, sizeof(char) * explen + 1);

	for (int i = 0; i < explen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
			Changeexp[idx++] = tok;
		else
		{
			switch (tok)
			{
			case '(':
				s.push(tok);
				break;
			case ')':
				while (1)
				{
					if (s.top() == '(')
					{
						s.pop();
						break;
					}
					Changeexp[idx++] = s.top();
					s.pop();
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!(s.empty()) && (Operator(s.top(), tok) >= 0))
				{
					Changeexp[idx++] = s.top();
					s.pop();
				}
				s.push(tok);
				break;
			}
		}
	}
	while (!(s.empty()))
	{
		Changeexp[idx++] = s.top();
		s.pop();
	}
	strcpy(exp, Changeexp);
	delete[]Changeexp;
}
int Stack_Calculator::Calculator(char *exp)
{
	explen = strlen(exp);

	for (int i = 0; i < explen; i++)
	{
		int num1 = 0, num2 = 0;

		if (isdigit(exp[i]))
			s.push(exp[i] - 48);
		else
		{
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();

			switch (exp[i])
			{
			case '+':
				s.push(num2 + num1);
				break;
			case '-':
				s.push(num2 - num1);
				break;
			case '*':
				s.push(num2 * num1);
				break;
			case '/':
				s.push(num2 / num1);
				break;
			}
		}
	}
	return s.top();
}