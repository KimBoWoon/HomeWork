#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class SnailArray
{
private:
	int size;
	int **Matrix;
public:
	SnailArray(int n);
	void Snail();
	void Print();
};
SnailArray::SnailArray(int n) : size(n)
{
	Matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		Matrix[i] = new int[size];
		memset(Matrix[i], 0, sizeof(int)*size);
	}
}
void SnailArray::Snail()
{
	int n = 1, x = 1, y = 0;
	while (n <= size * size)
	{
		for (int i = 0; i < size - x - y; i++)
			Matrix[y][i + y] = n++;
		for (int i = 0; i < size - y - y; i++)
			Matrix[i + y][size - x] = n++;
		for (int i = size - x - 1; i >= y; i--)
			Matrix[size - x][i] = n++;
		for (int i = size - x - 1; i > y; i--)
			Matrix[i][y] = n++;
		x++, y++;
	}
}
void SnailArray::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << Matrix[i][j] << "	";
		cout << endl;
	}
}
int main()
{
	int size;

	while (true)
	{
		cout << "달팽이 행렬의 size를 입력하세요 : ";
		cin >> size;
		if (size > 20 || size < 1)
			cout << "1~20사이의 숫자를 입력해주세요!" << endl;
		else
			break;
	}

	SnailArray snail(size);

	snail.Snail();

	snail.Print();
}