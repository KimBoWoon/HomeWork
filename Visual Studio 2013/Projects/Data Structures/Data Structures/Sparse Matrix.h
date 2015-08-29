#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 5
typedef int DataType;

class Matrix
{
private:
	int row, col;
	DataType elem;
public:
	friend ostream& operator<< (ostream& os, vector<Matrix *> M);

	void Setrow(int x);
	void Setcol(int x);
	void Setelem(DataType x);
	int Getrow() const;
	int Getcol() const;
	DataType Getelem() const;

	void SparseMatrixTable(DataType mat[SIZE][SIZE], DataType mat2[SIZE][SIZE], vector<Matrix *> &M);
	void FastTranspose(DataType mat[SIZE][SIZE], DataType mat2[SIZE][SIZE]);
	void MakeSparseMatrix(DataType mat2[SIZE][SIZE], vector<Matrix *> &M);
	void Change(vector<Matrix *> &M);
	void Sort(vector<Matrix *> &M) const;
	void PrintMatrix(DataType mat[SIZE][SIZE]) const;
	void InitMatrix(DataType mat[SIZE][SIZE]);
};
class Functor
{
public:
	bool operator() (Matrix *M1, Matrix *M2);
};