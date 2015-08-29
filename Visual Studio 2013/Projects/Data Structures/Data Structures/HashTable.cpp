#include <iostream>
#include <ctime>
#include <string>
using namespace std;

#define SIZE 100

template <typename T>
class Data {
public:
	T key;
	T data;
};
int HashFunc(int k) {
	return k % 100;
}
int StringHashFunc(string s) {
	int value = 0;

	for (int i = 0; i < s.size(); i++)
		value = (value << 4) + s[i];

	return value % SIZE;
}
int main() {
	Data<int> d1[100] = { 0 };
	Data<int> data1;
	Data<string> d2[SIZE];
	Data<string> data2;
	srand(time(NULL));

	/*for (int i = 0; i < 50; i++) {
		data1.key = rand();
		data1.data = i;

		while (d1[HashFunc(data1.key)].key != NULL)
			data1.key = rand();

		d1[HashFunc(data1.key)] = data1;
	}

	for (int i = 0; i < 100; i++) {
		cout << i << " key : " << d1[i].key << " data : " << d1[i].data << endl;
	}*/
	for (int i = 0; i < SIZE; i++)
		d2[i].key = "";

	for (int i = 0; i < 50; i++) {
		data2.key = "SZSR";
		cin >> data2.data;
		if (data2.data.compare("quit") == 0)
			break;

		/*if (data2.key != "")
			cout << "키값이 존재합니다!" << endl;*/

		d2[StringHashFunc(data2.key)] = data2;
	}

	for (int i = 0; i < 100; i++) {
		cout << i << " key : " << d2[i].key << " data : " << d2[i].data << endl;
	}
}