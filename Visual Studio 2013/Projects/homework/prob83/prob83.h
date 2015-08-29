#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
class matrix
{
public:
	template <class T>
	friend matrix<T> operator* (T value, const matrix<T>& mat);
	template <class T>
	friend ostream& operator<< (ostream& os, const matrix<T>& mat);
	friend istream& operator>> (istream& is, matrix<T>& mat);

	matrix(int nrows = 1, int ncols = 1, T initvalue = 0);
	//matrix(int nrows, int ncols, int initvalue);
	matrix(int nrows, int ncols, T* data);
	matrix(int nrows, int ncols, T** data);

	matrix(const matrix<T>& mat);

	~matrix();

	int getrows() const;
	int getcols() const;
	T* operator[] (int i) const;
	T& operator() (int i, int j) const;

	matrix<T> operator+ (const matrix<T>& mat) const;
	matrix<T> operator- (const matrix<T>& mat) const;
	matrix<T> operator* (const matrix<T>& mat) const;
	matrix<T> operator* (T value) const;

	matrix<T>& operator= (const matrix<T>& mat);
	matrix<T>& operator+= (const matrix<T>& mat);
	matrix<T>& operator-= (const matrix<T>& mat);
	matrix<T>& operator*= (const matrix<T>& mat);
	matrix<T>& operator*= (T value);

	bool operator== (const matrix<T>& mat) const;
	bool operator!= (const matrix<T>& mat) const;

	matrix<T> operator- () const;
	matrix<T>& transpose();
private:
	int rows;
	int cols;
	T** pdata;

	void allocatememory();
	void deletememory();
	void errormessage(string msg) const;
};