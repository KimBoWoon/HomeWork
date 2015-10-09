//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - 맥카시 함수
#include <iostream>
#include <fstream>
using namespace std;

int mocarthy(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;

		in >> n;

		cout << mocarthy(n) << endl;
	}
}

int mocarthy(int n) {
	if (n > 100)
		return n - 10;
	else
		return mocarthy(mocarthy(n + 11));
}