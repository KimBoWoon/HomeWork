#include "prob83.h"

template <class T>
matrix<T> operator* (T value, const matrix<T>& mat)
{
	matrix<T> r(mat.rows, mat.cols);
	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
			r.pdata[i][j] = value*mat.pdata[i][j];
	}
	return r;
}
template <class T>
ostream& operator<< (ostream& os, const matrix<T>& mat)
{
	os << mat.rows << "*" << mat.cols << endl;

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
			os << mat[i][j] << " ";
		os << endl;
	}

	return os;
}
template <class T>
istream& operator>> (istream& is, matrix<T>& mat)
{
	mat.deleteMemory();

	is >> mat.rows >> mat.cols;

	mat.allocateMemory();

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
			is >> mat[i][j];
	}

	return is;
}

template <class T>
matrix<T>::matrix(int nrows, int ncols, T initvalue) : rows(nrows), cols(ncols), pdata(NULL)
{
	allocatememory();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			pdata[i][j] = initvalue;
	}
}
//template <class T>
//matrix<T>::matrix(int nrows, int ncols, int initvalue) : rows(nrows), cols(ncols), pdata(NULL)
//{
//	allocatememory();
//
//	for(int i=0;i<rows;i++)
//	{
//		for(int j=0;j<cols;j++)
//			pdata[i][j]=initvalue;
//	}
//}
template <class T>
matrix<T>::matrix(int nrows, int ncols, T* data) : rows(nrows), cols(ncols), pdata(NULL)
{
	allocatememory();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			pdata[i][j] = data[i*cols + j];
	}
}
template <class T>
matrix<T>::matrix(int nrows, int ncols, T** data) : rows(nrows), cols(ncols), pdata(NULL)
{
	allocatememory();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			pdata[i][j] = data[i][j];
	}
}

template <class T>
matrix<T>::matrix(const matrix<T>& mat) : rows(mat.rows), cols(mat.cols), pdata(NULL)
{
	allocatememory();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			pdata[i][j] = mat.pdata[i][j];
	}
}

template <class T>
matrix<T>::~matrix()
{
	if (pdata != NULL)
		deletememory();
}

template <class T>
int matrix<T>::getrows() const	{ return rows; }
template <class T>
int matrix<T>::getcols() const	{ return cols; }
template <class T>
T* matrix<T>::operator[] (int i) const
{
	if (i < 0 || i >= rows)
		errormessage("asdf");
	return pdata[i];
}
template <class T>
T& matrix<T>::operator() (int i, int j) const
{
	if (i < 0 || i >= rows || j < 0 || j >= cols)
		errormessage("asdf");
	return pdata[i][j];
}

template <class T>
matrix<T> matrix<T>::operator+ (const matrix<T>& mat) const
{
	if (rows != mat.rows || cols != mat.cols)
		errormessage("asdf");
	matrix r(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			r.pdata[i][j] = pdata[i][j] + mat.pdata[i][j];
	}
	return r;
}
template <class T>
matrix<T> matrix<T>::operator- (const matrix<T>& mat) const
{
	if (rows != mat.rows || cols != mat.cols)
		errormessage("asdf");
	matrix r(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			r.pdata[i][j] = pdata[i][j] - mat.pdata[i][j];
	}
	return r;
}
template <class T>
matrix<T> matrix<T>::operator* (const matrix<T>& mat) const
{
	if (cols != mat.rows)
		errormessage("asdf");
	matrix r(rows, mat.cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < mat.cols; k++)
				r.pdata[i][k] += pdata[i][j] * mat.pdata[j][k];
		}
	}

	return r;
}
template <class T>
matrix<T> matrix<T>::operator* (T value) const
{
	return value*(*this);
}

template <class T>
matrix<T>& matrix<T>::operator= (const matrix<T>& mat)
{
	if (&mat == this)
		return *this;
	deletememory();
	rows = mat.rows;
	cols = mat.cols;
	allocatememory();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			pdata[i][j] = mat.pdata[i][j];
	}

	return *this;
}
template <class T>
matrix<T>& matrix<T>::operator+= (const matrix<T>& mat)
{
	*this = *this + mat;

	return *this;
}
template <class T>
matrix<T>& matrix<T>::operator-= (const matrix<T>& mat)
{
	*this = *this - mat;

	return *this;
}
template <class T>
matrix<T>& matrix<T>::operator*= (const matrix<T>& mat)
{
	*this = *this * mat;

	return *this;
}
template <class T>
matrix<T>& matrix<T>::operator*= (T value)
{
	matrix r(*this);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			r.pdata[i][j] = r.pdata[i][j] * value;
	}
	*this = R;
	return *this;
}

template <class T>
bool matrix<T>::operator== (const matrix<T>& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		return false;
	matrix r(*this);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (r.pdata[i][j] != mat.pdata[i][j]) return false;
	return true;
}
template <class T>
bool matrix<T>::operator!= (const matrix<T>& mat) const
{
	return !((*this) == mat);
}

template <class T>
matrix<T> matrix<T>::operator- () const
{
	matrix r(*this);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			r.pdata[i][j] = -r.pdata[i][j];
	}
	return r;
}
template <class T>
matrix<T>& matrix<T>::transpose()
{
	matrix p(*this);
	matrix r(cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			r.pdata[i][j] = p.pdata[j][i];
	}
	*this = r;
	return *this;
}

template <class T>
void matrix<T>::allocatememory()
{
	if (pdata != NULL)
		deletememory();
	pdata = new T*[rows];
	if (pdata == NULL)
		errormessage("asdf");
	pdata[0] = new T[rows*cols];
	if (pdata[0] == NULL)
	{
		delete[] pdata;
		errormessage("asdf");
	}
	for (int i = 1; i < rows; i++)
		pdata[i] = pdata[0] + i*cols;
}
template <class T>
void matrix<T>::deletememory()
{
	delete[] pdata[0];
	delete[] pdata;
	pdata = NULL;
}
template <class T>
void matrix<T>::errormessage(string msg) const
{
	cout << "Error: " << msg << endl;
	exit(1);
}