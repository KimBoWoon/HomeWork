#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
private:
	int **matrix;
	int row, col;

	Matrix(int row, int col);
public:
	Matrix();

	Matrix operator* (Matrix& m);
	Matrix operator+ (Matrix& m);

	void PrintMatrix();
};

Matrix::Matrix()
{
	cout << "n X m 행렬을 만듭니다." << endl;
	cout << "n과 m을 입력하세요." << endl;
	cin >> row >> col;

	/*if (matrix)
	{
		for (int i = 0; i < row; i++)
			delete [i]matrix;
		delete matrix;
	}*/

	matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		memset(matrix[i], 0, sizeof(int) * col);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> matrix[i][j];
	}
}
Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;

	matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		memset(matrix[i], 0, sizeof(int) * col);
	}
}
Matrix Matrix::operator* (Matrix& m)
{
	Matrix mul(row, m.col);

	for (int t = 0; t < row; t++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				mul.matrix[t][i] += matrix[i][j] * m.matrix[j][i];
		}
	}
	return mul;
}
Matrix Matrix::operator+ (Matrix& m)
{
	Matrix plus(row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			plus.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
	}
	return plus;
}
void Matrix::PrintMatrix()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	Matrix m1, m2, m3, m4;

	m3 = m1 + m2;
	m3.PrintMatrix();

	m4 = m1 * m2;
	m4.PrintMatrix();
}