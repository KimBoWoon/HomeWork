#ifndef __ACCUMULATED_MONEY__
#define __ACCUMULATED_MONEY__

#include <iostream>
#include <fstream>
using namespace std;

class AccumulatedMoney
{
private:
	ifstream input;
	ofstream output;
	double Money;
public:
	AccumulatedMoney();
	~AccumulatedMoney();
	int GetMoney();
	void Deposit(double Money);
	void Withdraw(double Money);
	void PrintMoney() const;
};
class BankBalance
{
private:
	ifstream input;
	ofstream output;
	int Money;
public:
	BankBalance();
	~BankBalance();
	int GetMoney();
	void Deposit(int Money);
	void Withdraw(int Money);
	void PrintMoney() const;
};

#endif