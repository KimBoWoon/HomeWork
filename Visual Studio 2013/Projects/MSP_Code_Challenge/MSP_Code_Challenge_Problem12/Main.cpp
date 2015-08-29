#include "Anagram.h"

int main()
{
	char c[2] = { 'y' };

	while (c[0] == 'y' || c[0] == 'Y')
	{
		cout << "첫 번째 문자열을 입력하세요" << endl;
		Anagram str1;
		cout << "두 번째 문자열을 입력하세요" << endl;
		Anagram str2;

		if (str1 == str2)
			cout << "아나그램 맞다" << endl;
		else
			cout << "아나그램 아니다" << endl;

		cout << "계속 진행하시겠습니까? (y/n)" << endl;
		cin.getline(c, 2);
	}
}