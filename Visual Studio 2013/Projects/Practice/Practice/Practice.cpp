#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <functional>
using namespace std;

typedef struct position {
	int x;
	int y;
} Position;

int comp(const void* x, const void* y) {
	if ((*(Position*)x).x == (*(Position*)y).x) {
		return (*(Position*)x).y - (*(Position*)y).y;
	}
	return (*(Position*)x).x - (*(Position*)y).x;
}

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	while (testCase--) {
		int cafeNum, cnt;
		Position* pos;

		in >> cafeNum;
		pos = new Position[cafeNum];
		memset(pos, 0, sizeof(Position) * cafeNum);

		for (int i = 0; i < cafeNum; i++) {
			int x, y;
			in >> x >> y;
			Position p = { x, y };
			pos[i] = p;
		}

		qsort(pos, cafeNum, sizeof(Position), comp);

		in >> cnt;
		for (int i = 0; i < cnt; i++) {
			int a;
			in >> a;
			cout << pos[a - 1].x << " " << pos[a - 1].y << endl;
		}

		/*qsort(pos, cafeNum, sizeof(Position), comp);

		for (int i = 0; i < cafeNum; i++)
			cout << pos[i].x << " " << pos[i].y << endl;
		cout << endl;*/
	}
}