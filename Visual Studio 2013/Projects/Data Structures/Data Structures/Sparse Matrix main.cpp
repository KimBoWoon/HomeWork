#include "Sparse Matrix.h"

int main()
{
	vector<Matrix *> M;
	Matrix mat;

	DataType matrix[SIZE][SIZE] = {
		0, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		2, 3, 0, 0, 0,
		4, 5, 6, 0, 0,
		7, 8, 9, 10, 0
	};
	DataType matrix2[SIZE][SIZE] = { 0 };

	mat.SparseMatrixTable(matrix, matrix2, M);

	mat.MakeSparseMatrix(matrix2, M);

	mat.PrintMatrix(matrix2);

	mat.Change(M);

	mat.Sort(M);

	cout << endl << "<Matrix Transpose>" << endl << endl;

	cout << M;

	mat.InitMatrix(matrix2);

	mat.MakeSparseMatrix(matrix2, M);

	mat.PrintMatrix(matrix2);
}