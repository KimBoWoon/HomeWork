//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰����� ���� - ��ī�� �Լ�
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