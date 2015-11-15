//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string encoding(string str);
string decoding(string str);

int main() {
	int testCase;
	ifstream cin("input.txt");

	//freopen("input.txt", "r", stdin);

	cin >> testCase;

	while (testCase--) {
		int mode;
		string str;

		cin >> mode >> str;

		if (mode == 1)
			cout << encoding(str) << endl;
		else
			cout << decoding(str) << endl;
	}
}

string encoding(string str) {
	char c = str[0];
	int cnt = 1;
	string result = "";

	for (int i = 1; i < str.size(); i++) {
		if (c == str[i])
			cnt++;
		else
			result += cnt + c;
	}
	

	return result;
}

string decoding(string str) {
	return "Fuck";
}