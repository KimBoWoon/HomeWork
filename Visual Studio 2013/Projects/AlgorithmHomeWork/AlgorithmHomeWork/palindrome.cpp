//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰��� ���� - �Ǻθ��� �̿��� �Ӹ���� �Ǻ�
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
	// ȸ���� ���
	if (x >= y)
		return 1;
	// ȸ���� �ƴ� ���
	else if (str[x] != str[y])
		return 0;
	// ȸ������ �˻�
	else if (str[x] == str[y])
		return palindrome(str, x + 1, y - 1);
}