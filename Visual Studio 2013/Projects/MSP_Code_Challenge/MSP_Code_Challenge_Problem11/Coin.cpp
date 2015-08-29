#include "Coin.h"

Coin::Coin()
{
	cout << "거스름돈 입력" << endl;
	cin >> coin;
}
void Coin::compute()
{
	int coin500 = 0, coin100 = 0, coin50 = 0, coin10 = 0, temp = 0;

	if (coin < 0)
	{
		cout << "양수인 " << abs(coin) << "원으로 계산을 진행합니다." << endl;
		coin = abs(coin);
	}
	cout << "거스름돈<동전 수>" << endl;
	while (true)
	{
		if (coin >= 500)
		{
			coin500++;
			coin -= 500;
			continue;
		}
		if (coin >= 100)
		{
			coin100++;
			coin -= 100;
			continue;
		}
		if (coin >= 50)
		{
			coin50++;
			coin -= 50;
			continue;
		}
		if (coin >= 10)
		{
			coin10++;
			coin -= 10;
			continue;
		}
		break;
	}
	cout << "500원 동전 : " << coin500 << endl;
	cout << "100원 동전 : " << coin100 << endl;
	cout << "50원 동전 : " << coin50 << endl;
	cout << "10원 동전 : " << coin10 << endl;
}