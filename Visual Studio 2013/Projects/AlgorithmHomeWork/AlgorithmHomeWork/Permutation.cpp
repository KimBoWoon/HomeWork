// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - 정렬된 순열 구하기
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fact(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int size = 0, cnt = 0, f = 0;
		string str = "abcdefghijkl";
		string result = "";
		
		in >> size >> cnt;
		
		for (int f = fact(--size), k = cnt - 1; size >= 1; size--) {
			int select = k / f;
			k %= f;

			result += str[select];
			str.erase(select, 1);
			f /= size;
		}
		cout << result << str[0] << endl;
	}
}

int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

//#include<iostream>
//#include<fstream>
//
//#define MAX 12
//
//using namespace std;
//
//int factorial(int n);
//void sort(char *set, int k);
//
//int main(void)
//{
//	ifstream inStream;
//	inStream.open("input.txt");
//
//	int numTestCases;
//
//	inStream >> numTestCases;
//
//	for (int i = 0; i < numTestCases; i++) {
//		char set[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };
//		int number, cases, lcases;
//		inStream >> number >> cases;
//
//		number -= 1;
//		int k = factorial(number);
//		cases = cases - 1;
//		while (number >= 1){
//			lcases = cases / k;
//			cases %= k;
//
//			cout << set[lcases];
//			sort(set, lcases);
//			k /= number;
//			number--;
//		}
//		cout << set[0];
//		cout << endl;
//	}
//}
//
//int factorial(int n){
//
//	if (n < 1) 
//		return 1;
//	else 
//		return n*factorial(n - 1);
//
//}
//
//void sort(char *set, int k){
//
//	char temp;
//	temp = set[k];
//	for (int i = k; i < MAX; i++){
//		set[i] = set[i + 1];
//	}
//	set[11] = temp;
//}