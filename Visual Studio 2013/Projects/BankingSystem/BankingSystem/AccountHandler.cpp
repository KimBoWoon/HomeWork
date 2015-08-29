#include "AccountHandler.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : Tail(NULL), cur(NULL)
{
	Head = new Account("", -1, -1);
}
void AccountHandler::MakeAccount()
{
	char chioce;
	Account* NewNode;

	cout << "계좌 선택" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택 : ";

	while (true)
	{
		chioce = _getch();
		cout << endl;

		if (chioce == '1')
		{
			NewNode = MakeNomalAccount();
			break;
		}
		else if (chioce == '2')
		{
			NewNode = MakeHighCreditAccount();
			break;
		}
		else
		{
			cout << endl << "잘못된 입력입니다!" << endl;
			cout << "다시 입력하세요!" << endl;
			continue;
		}
	}

	if (Head->Next == NULL)
		Head->Next = NewNode;
	else
		Tail->Next = NewNode;

	Tail = NewNode;
}
Account* AccountHandler::MakeNomalAccount()
{
	//char Name[10];
	String Name;
	int Money, AccountNumber, rate;

	cout << "보통예금계좌 개설" << endl;
	cout << "이    름 : ";
	cin >> Name;
	cout << "계좌번호 : ";
	cin >> AccountNumber;
	cout << "입 금 액 : ";
	cin >> Money;
	cout << "이 자 율 : ";
	cin >> rate;

	return new NomalAccount(Name, AccountNumber, rate, Money);
}
Account* AccountHandler::MakeHighCreditAccount()
{
	//char Name[10];
	String Name;
	int Money, AccountNumber, rate, specrate;

	cout << "신용신뢰계좌 개설" << endl;
	cout << "이    름 : ";
	cin >> Name;
	cout << "계좌번호 : ";
	cin >> AccountNumber;
	cout << "입 금 액 : ";
	cin >> Money;
	cout << "이 자 율 : ";
	cin >> rate;

	while (true)
	{
		cout << "신용등급 : ";
		cin >> specrate;

		if (specrate == 1)
			return new HighCreditAccount(Name, AccountNumber, rate, 7, Money);
		else if (specrate == 2)
			return new HighCreditAccount(Name, AccountNumber, rate, 4, Money);
		else if (specrate == 3)
			return new HighCreditAccount(Name, AccountNumber, rate, 2, Money);
		else
		{
			cout << endl << "잘못된 입력입니다!" << endl;
			cout << "다시 입력하세요!" << endl;
			continue;
		}
	}
}
void AccountHandler::DepositORWithdraw(char choice)
{
	int Account, Money;

	cout << "계좌번호 : ";
	cin >> Account;

	cur = Head->Next;

	while (cur->AccountNumber != Account)
	{
		if (cur->Next == NULL)
		{
			cout << "존재 하지 않는 정보입니다!";
			return;
		}
		else
			cur = cur->Next;
	}

	try
	{
		if (choice == '2')
		{
			cout << "입 금 액 : ";
			cin >> Money;
			cur->Deposit(Money);
			cout << "입금 완료" << endl;
		}
		else if (choice == '3')
		{
			cout << "출 금 액 : ";
			cin >> Money;
			cur->Withdraw(Money);
			cout << "출금 완료" << endl;
		}
	}
	catch (Exception e)
	{
		e.ShowExceptionInfo();
	}
}
void AccountHandler::AllPrint()
{
	cur = Head->Next;

	while (cur != NULL)
	{
		cur->Print();

		cur = cur->Next;
	}
}
void AccountHandler::MenuView() const
{
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 전체고객 잔액조회" << endl;
}