#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "Account.h"

class AccountHandler
{
private:
	Account* Head;
	Account* Tail;
	Account* cur;
protected:
	Account* MakeNomalAccount();
	Account* MakeHighCreditAccount();
public:
	AccountHandler();

	void MakeAccount();
	void DepositORWithdraw(char choice);

	void MenuView() const;
	void AllPrint();
};

#endif