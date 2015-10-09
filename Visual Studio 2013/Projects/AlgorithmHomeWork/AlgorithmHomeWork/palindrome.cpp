//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - 되부름을 이용한 팰린드롬 판별
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int palindrome(string str, int x, int y);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		string str = "";

		in >> str;

		cout << palindrome(str, 0, str.size() - 1) << endl;
	}
}

int palindrome(string str, int x, int y) {
	// 회문일 경우
	if (x >= y)
		return 1;
	// 회문이 아닐 경우
	else if (str[x] != str[y])
		return 0;
	// 회문인지 검사
	else if (str[x] == str[y])
		return palindrome(str, x + 1, y - 1);
}