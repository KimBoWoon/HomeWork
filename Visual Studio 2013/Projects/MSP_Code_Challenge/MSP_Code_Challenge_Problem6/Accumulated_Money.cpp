#include "Accumulated_Money.h"

AccumulatedMoney::AccumulatedMoney()
{
	input.open("적립금.txt");

	if (input.fail())
	{
		cerr << "파일을 찾을 수 없습니다!";
		exit(1);
	}

	input >> Money;
	input.close();
}
AccumulatedMoney::~AccumulatedMoney()
{
	output.open("적립금.txt");
	output << Money;
	output.close();
}
int AccumulatedMoney::GetMoney()	{ return Money; }
void AccumulatedMoney::Deposit(double Money)
{
	if (Money > 0)
	{
		this->Money += Money;
		cout << Money << "원이 적립되었습니다." << endl << endl;
	}
	else
		cout << "0보다 작을 수 없습니다." << endl;
}
void AccumulatedMoney::Withdraw(double Money)
{
	if (Money > 0 && this->Money >= Money)
		this->Money -= Money;
	else
		cout << "현재 가지고 있는 잔액보다 클 수 없습니다!" << endl;
}
void AccumulatedMoney::PrintMoney() const	{ cout << "적립금 : " << Money; }