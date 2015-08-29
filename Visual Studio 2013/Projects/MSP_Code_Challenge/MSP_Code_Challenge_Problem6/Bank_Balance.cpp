#include "Accumulated_Money.h"

BankBalance::BankBalance()
{
	input.open("통장잔고.txt");

	if (input.fail())
	{
		cerr << "파일을 찾을 수 없습니다!";
		exit(1);
	}

	input >> Money;
	input.close();
}
BankBalance::~BankBalance()
{
	output.open("통장잔고.txt");
	output << Money;
	output.close();
}
int BankBalance::GetMoney()	{ return Money; }
void BankBalance::Deposit(int Money)
{
	if (Money > 0)
		this->Money += Money;
	else
		cout << "0보다 작을 수 없습니다." << endl;
}
void BankBalance::Withdraw(int Money)
{
	if (Money > 0 && this->Money >= Money)
		this->Money -= Money;
	else
		cout << "현재 가지고 있는 잔액보다 클 수 없습니다!" << endl;
}
void BankBalance::PrintMoney() const	{ cout << "현재 통장 잔고 : " << Money; }