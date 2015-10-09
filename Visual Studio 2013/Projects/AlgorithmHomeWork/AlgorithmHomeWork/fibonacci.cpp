//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - 되부름을 이용한 피보나치수 계산
#include <iostream>
#include <fstream>
using namespace std;

int fibo(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n;

		in >> n;

		cout << fibo(n) << endl;
	}
}

int fibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}