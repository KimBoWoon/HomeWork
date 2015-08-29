#include <iostream>
using namespace std;

class Prime_Number
{
private:
	int start, end;
public:
	Prime_Number();
	bool PrimeNumber(int x);
	void Execute();
};

Prime_Number::Prime_Number()
{
	cout << "1부터 300사이에 두 숫자를 입력하세요 : ";
	cin >> start >> end;

	if (start < 1 || end > 300)
		throw "범위를 벗어났습니다! 프로그램을 종료합니다.";
}
bool Prime_Number::PrimeNumber(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void Prime_Number::Execute()
{
	for (; start < end; start++)
	{
		if (PrimeNumber(start))
			cout << start << endl;
	}
}

int main()
{
	try
	{
		Prime_Number m;

		m.Execute();
	}
	catch (const char *s)
	{
		cout << s << endl;
	}
}