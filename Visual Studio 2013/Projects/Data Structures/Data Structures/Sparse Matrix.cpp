#include "Sparse Matrix.h"

bool Functor::operator() (Matrix *M1, Matrix *M2)	{ return M1->Getrow() < M2->Getrow(); }

void Matrix::Setrow(int x)	{ row = x; }
void Matrix::Setcol(int x)	{ col = x; }
void Matrix::Setelem(DataType x)	{ elem = x; }
int Matrix::Getrow() const	{ return row; }
int Matrix::Getcol() const	{ return col; }
DataType Matrix::Getelem() const	{ return elem; }

void Matrix::SparseMatrixTable(DataType mat[SIZE][SIZE], DataType mat2[SIZE][SIZE], vector<Matrix *> &M)
{
	int cnt = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (mat[i][j] != 0)
			{
				M.push_back(new Matrix);
				M[cnt]->Setcol(j);
				M[cnt]->Setrow(i);
				M[cnt++]->Setelem(mat[i][j]);
			}
		}
	}
	cout << M;
}
void Matrix::MakeSparseMatrix(DataType mat2[SIZE][SIZE], vector<Matrix *> &M)
{
	int cnt = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (M[cnt]->Getrow() == i && M[cnt]->Getcol() == j)
				mat2[i][j] = M[cnt++]->Getelem();
			if (cnt == M.size())
				return;
		}
	}
}
void Matrix::Change(vector<Matrix *> &M)
{
	for (size_t i = 0; i < M.size(); i++)
	{
		DataType temp = M[i]->Getcol();
		M[i]->Setcol(M[i]->Getrow());
		M[i]->Setrow(temp);
	}
}
void Matrix::Sort(vector<Matrix *> &M) const
{
	Functor Less;

	sort(M.begin(), M.end(), Less);
}
void Matrix::PrintMatrix(DataType mat[SIZE][SIZE]) const
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << mat[i][j] << "	";
		cout << endl;
	}
}
void Matrix::InitMatrix(DataType mat[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			mat[i][j] = 0;
	}
}
ostream& operator<< (ostream& os, vector<Matrix *> M)
{
	for (size_t i = 0; i < M.size(); i++)
		cout << "row : " << M[i]->Getrow() << " col : " << M[i]->Getcol() << " elem : " << M[i]->Getelem() << endl;
	return os;
}