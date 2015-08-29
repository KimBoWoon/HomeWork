#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "BAABABAABABAABAABABAA";
	string p = "BAABABAA";
	int* pi = new int[s.size()];

	pi[0] = -1;

	for (int i = 0, j = -1; i < p.size();) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			pi[i] = j;
		}
		else
			j = pi[j];
	}
	for (int i = 0; i < p.size() + 1; i++)
		cout << pi[i] << " ";
	cout << endl;
	for (int i = 0, j = 0; i < s.size();) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else
			j = pi[j];
		if (p.size() == j) {
			cout << "패턴 발견" << endl;
			j = 0; //break;
		}
	}
}