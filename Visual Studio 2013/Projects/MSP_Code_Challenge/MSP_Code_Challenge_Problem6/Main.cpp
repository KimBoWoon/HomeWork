#include "Accumulated_Money.h"

int main()
{
	BankBalance bb;
	AccumulatedMoney am;
	int Money, AMMoney;
	char cur;

	bb.PrintMoney();
	cout << ", ";
	am.PrintMoney();
	cout << endl << endl;

	while (true)
	{
		cout << "구매하실 물건의 가격 : ";
		cin >> Money;
		if (Money > bb.GetMoney())
		{
			cout << "현재 통장 잔고가 부족합니다. 다시 입력해주세요." << endl;
			continue;
		}
		cout << "적립금을 사용하시겠습니까? (y/n) : ";
		cin >> cur;
		cout << endl;
		if (cur == 'y')
		{
			cout << "사용하실 적립금을 입력해주세요. : ";
			while (true)
			{
				cin >> AMMoney;

				if (AMMoney <= 0)
					cout << "0보다 작을 수 없습니다. 다시 입력해주세요. : ";
				else
					break;
			}
			am.Withdraw(AMMoney);
			if (Money - AMMoney > 0)
				bb.Withdraw(Money - AMMoney);
			cout << "적립금을 사용하여 " << Money - AMMoney << "원이 결제되었습니다." << endl;
			break;
		}
		else if (cur == 'n')
		{
			bb.Withdraw(Money);
			am.Deposit(Money * 0.05);
			break;
		}
		else
			cout << "다시 입력해주세요!" << endl;
	}
	bb.PrintMoney();
	cout << ", ";
	am.PrintMoney();
	cout << endl;
}