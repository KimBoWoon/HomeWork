#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__

#include "Define.h"
#include "NomalAccount.h"

class HighCreditAccount : public NomalAccount
{
private:
	int SpecialRate;
public:
	//HighCreditAccount(char* n, int Account, int rate, int specrate, int money = 0) : NomalAccount(n, Account, rate, money), SpecialRate(specrate)	{}
	HighCreditAccount(String n, int Account, int rate, int specrate, int money = 0) : NomalAccount(n, Account, rate, money), SpecialRate(specrate)	{}

	virtual void Deposit(int money)
	{
		NomalAccount::Deposit(money);
		Account::Deposit(money * (SpecialRate / 100.0));
	}
};

#endif