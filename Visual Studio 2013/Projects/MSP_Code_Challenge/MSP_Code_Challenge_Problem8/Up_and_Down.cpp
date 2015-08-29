#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int random, user = -1, cnt = 0;

	srand(time(NULL));
	random = rand() % 50;

	cout << "0~50 사이의 수를 입력해주세요." << endl;
	while (random != user && cnt < 10)
	{
		cin >> user;
		if (user > 50 || user < 0)
		{
			cout << "0부터 50사이의 숫자를 입력해주세요" << endl;
			continue;
		}
		if (user == random)
			break;
		if (user > random)
			cout << "정답보다 큰 값이 입력되었습니다!" << endl << "다시 입력해주세요" << endl;
		else
			cout << "정답보다 작은 값이 입력되었습니다!" << endl << "다시 입력해주세요" << endl;
		cnt++;
	}
	if (cnt == 10)
		cout << "시도 가능횟수를 초과했습니다." << endl;
	else
		cout << cnt + 1 << "번째에 성공했습니다!" << endl;
}