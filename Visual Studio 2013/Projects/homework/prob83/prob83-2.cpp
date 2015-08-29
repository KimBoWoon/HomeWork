#include "prob79.h"
#include "prob83-1.cpp"

typedef matrix<int> matrixint;
typedef matrix<complex> matrixcomplex;

void testsimplecaseint();
void testsimplecasecomplex();
void testdatafromfile();
template <class T> void readmatrix(ifstream& instream, matrix<T>& mat);

void main(void)
{
	testsimplecaseint();
	testsimplecasecomplex();
	testdatafromfile();
}
void testsimplecaseint()
{
	int testdata1[6] = { 1, 2, 3, 4, 5, 6 };
	int testdata2[6] = { 6, 5, 4, 3, 2, 1 };

	matrixint m1(2, 2, 1);
	matrixint m2(2, 3, testdata1);
	matrixint m3(3, 2, testdata2);
	matrixint m4(m3);
	matrixint m5, m6(2, 3, 1), m7(3, 4, 1), m8(4, 2, 1), m9;

	cout << m1.getrows() << " " << m1.getcols() << endl;
	m4(0, 0) = 1;
	m4(0, 1) = 2;
	cout << m4[0][0] << " " << m4[0][1] << endl;
	cout << m4(1, 0) << " " << m4(1, 1) << endl;
	cout << m4[2][0] << " " << m4[2][1] << endl;

	m3 = m3;
	cout << m3;

	m5 = m3 + m4;
	cout << m5;

	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m4 = m5 - m4;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;

	m9 = m6*m7*m8 + m1;
	cout << m9;
	m8 = m7 = m6 = m5;
	cout << m8;

	m4 = m4 * 2;
	cout << m4;

	m4 = 2 * m4;
	cout << m4;

	m5 = m2*m3;
	cout << m5;

	m2 *= m3;
	cout << m2;

	m2 += m1;
	cout << m2;

	m2 -= m1;
	cout << m2;

	m2 = -m1 + 2 * m2;
	cout << m2;

	m7 = m4;
	m8 = m7*m4.transpose();
	cout << m8;
}
void testsimplecasecomplex()
{
	complex testdata1[6] = { complex(1, 1), complex(2, 2), complex(3, 3), complex(4, 4), complex(5, 5), complex(6, 6) };
	complex testdata2[6] = { complex(6, 6), complex(5, 5), complex(4, 4), complex(3, 3), complex(2, 2), complex(1, 1) };

	matrixcomplex m1(2, 2, complex(1, 1));
	matrixcomplex m2(2, 3, testdata1);
	matrixcomplex m3(3, 2, testdata2);
	matrixcomplex m4(m3);
	matrixcomplex m5, m6(2, 3, complex(1, 1)), m7(3, 4, complex(1, 1)), m8(4, 2, complex(1, 1)), m9;

	cout << m1.getrows() << " " << m1.getcols() << endl;
	m4(0, 0) = complex(1, 1);
	m4(0, 1) = complex(2, 2);
	cout << m4[0][0] << " " << m4[0][1] << endl;
	cout << m4(1, 0) << " " << m4(1, 1) << endl;
	cout << m4[2][0] << " " << m4[2][1] << endl;

	m3 = m3;
	cout << m3;

	m5 = m3 + m4;
	cout << m5;

	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m4 = m5 - m4;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;

	m9 = m6*m7*m8 + m1;
	cout << m9;
	m8 = m7 = m6 = m5;
	cout << m8;

	m4 = m4*complex(2, 2);
	cout << m4;

	m4 = complex(2, 2)*m4;
	cout << m4;

	m5 = m2*m3;
	cout << m5;

	m2 *= m3;
	cout << m2;

	m2 += m1;
	cout << m2;

	m2 -= m1;
	cout << m2;

	m2 = -m1 + complex(2, 2)*m2;
	cout << m2;

	m7 = m4;
	m8 = m7*m4.transpose();
	cout << m8;
}
void testdatafromfile()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> cases;

	for (int i = 0; i < cases / 2; i++)
	{
		matrixint m[4], m0;

		for (int j = 0; j < 4; j++)
			readmatrix(inStream, m[j]);

		m0 = m[0] * m[1] * m[2] + m[3];

		cout << m0;
		cout << m0[0][0] << " " << m0[m0.getrows() - 1][m0.getcols() - 1] << endl;
	}
	for (int i = 0; i < cases / 2; i++)
	{
		matrixcomplex m[4], m0;

		for (int j = 0; j < 4; j++)
			readmatrix(inStream, m[j]);

		m0 = m[0] * m[1] * m[2] + m[3];

		cout << m0;
		cout << m0[0][0] << " " << m0[m0.getrows() - 1][m0.getcols() - 1] << endl;
	}
	inStream.close();
}
#define MAX_SIZE 10000
template<class T>
void readmatrix(ifstream& inStream, matrix<T>& mat)
{
	T data[MAX_SIZE];
	int row, col;

	inStream >> row >> col;

	for (int i = 0; i < row*col; i++)
		inStream >> data[i];

	mat = matrix<T>(row, col, data);
}