#ifndef __ACCOUNT__
#define __ACCOUNT__

#include "Define.h"

class Account
{
private:
	String Name;
	int Money, AccountNumber;
	Account* Next;
	friend class AccountHandler;
public:
	//Account(char* n, int Account, int money = 0);
	Account(String n, int Account, int money = 0);
	//Account(const Account &p);
	//~Account();

	//Account& operator= (const Account& a);

	virtual void Deposit(int money);
	void Withdraw(int money);

	void Print() const;
};

#endif