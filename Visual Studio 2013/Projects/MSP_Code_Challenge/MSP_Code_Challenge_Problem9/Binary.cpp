#include "Binary.h"

Binary::Binary() : bin(1), cnt(0)
{
	cout << "음이 아닌 정수 k를 입력하세요 : ";
	cin >> k;
	cout << "음이 아닌 정수 n를 입력하세요 : ";
	cin >> n;

	bin <<= k;
}
void Binary::PrintBinary()
{
	for (int i = 0; i < bin; i++)
	{
		tempnum = i;

		for (int j = 0; j < k; j++)
		{
			if ((0x1 & tempnum) == 1)
				cnt++;
			tempnum >>= 1;
		}
		if (cnt == n)
		{
			tempnum = i;
			tempbin = bin / 2;
			for (int j = 0; j < k; j++)
			{
				cout << ((tempbin & tempnum) ? 1 : 0);
				tempbin >>= 1;
			}
			cout << " ";
		}
		cnt = 0;
	}
	cout << endl;
}