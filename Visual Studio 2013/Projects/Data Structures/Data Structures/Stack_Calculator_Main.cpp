#include "Stack_Calculator.h"

int main()
{
	/*char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	char exp4[] = "4*2+8";
	char exp5[] = "(1*(2+3))/4";

	Stack_Calculator.Change(exp1);
	Change(exp2);
	Change(exp3);
	Change(exp4);
	Change(exp5);

	cout << exp1 << " = " << Calculator(exp1) << endl;
	cout << exp2 << " = " << Calculator(exp2) << endl;
	cout << exp3 << " = " << Calculator(exp3) << endl;
	cout << exp4 << " = " << Calculator(exp4) << endl;
	cout << exp5 << " = " << Calculator(exp5) << endl;*/

	while (1)
	{
		Stack_Calculator sc;

		sc.Change(sc.Getexp());

		cout << "후위 표기식 : " << sc.Getexp() << " = " << sc.Calculator(sc.Getexp()) << endl;
	}
}