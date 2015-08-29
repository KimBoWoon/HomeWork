#ifndef __NOMAL_ACCOUNT__
#define __NOMAL_ACCOUNT__

#include "Define.h"
#include "Account.h"

class NomalAccount : public Account
{
private:
	int InterRate;
public:
	//NomalAccount(char* n, int Account, int rate, int money = 0) : Account(n, Account, money), InterRate(rate)	{}
	NomalAccount(String n, int Account, int rate, int money = 0) : Account(n, Account, money), InterRate(rate)	{}

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (InterRate / 100.0));
	}
};

#endif