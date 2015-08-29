#include <iostream>
using namespace std;

void translation(int x, int y, int tx, int ty) {
	int arr[3][1] = { 0 };
	int identity[3][3] = {
		{ 1, 0, tx },
		{ 0, 1, ty },
		{ 0, 0, 1 },
	};

	for (int i = 0; i < 2; i++) {
		arr[i][0] = (identity[i][0] * x) + (identity[i][1] * y) + (identity[i][2] * 1);
	}

	cout << "newX : " << arr[0][0] << ", newY : " << arr[1][0] << endl;
}
void translation(int x, int y, int z, int tx, int ty, int tz) {
	int arr[4][1] = { 0 };
	int identity[4][4] = {
		{ 1, 0, 0, tx },
		{ 0, 1, 0, ty },
		{ 0, 0, 1, tz },
		{ 0, 0, 0, 1 }
	};

	for (int i = 0; i < 4; i++) {
		arr[i][0] = (identity[i][0] * x) + (identity[i][1] * y) + (identity[i][2] * z) + (identity[i][3] * 1);
	}

	cout << "newX : " << arr[0][0] << ", newY : " << arr[1][0] << ", newZ : " << arr[2][0] << endl;
}

int main() {
	int x, y, z, tx, ty, tz;

	cout << "----- 2���� -----" << endl;
	cout << "���� �Է� >> ";
	cin >> x >> y;
	cout << "�̵��� ��ǥ �Է� >> ";
	cin >> tx >> ty;
	translation(x, y, tx, ty);

	cout << "----- 3���� -----" << endl;
	cout << "���� �Է� >> ";
	cin >> x >> y >> z;
	cout << "�̵��� ��ǥ �Է� >> ";
	cin >> tx >> ty >> tz;
	translation(x, y, z, tx, ty, tz);
}