#include <iostream>
using namespace std;

typedef unsigned long ULONG;

typedef struct M
{
	ULONG Matrix[2][2];
}Matrix;

ULONG Fibonacci(int n);
Matrix Power(Matrix m, int n);
Matrix Multiply(Matrix x, Matrix y);

int main()
{
	int n;

	scanf_s("%d", &n, sizeof(int));

	printf("%lu\n", Fibonacci(n));
}
ULONG Fibonacci(int n)
{
	Matrix m;

	m.Matrix[0][0] = 1;
	m.Matrix[0][1] = 1;
	m.Matrix[1][0] = 1;
	m.Matrix[1][1] = 0;

	m = Power(m, n);

	return m.Matrix[0][1];
}
Matrix Power(Matrix m, int n)
{
	if (n > 1)
	{
		m = Power(m, n / 2);
		m = Multiply(m, m);

		if (n & 1)
		{
			Matrix m2;

			m2.Matrix[0][0] = 1;
			m2.Matrix[0][1] = 1;
			m2.Matrix[1][0] = 1;
			m2.Matrix[1][1] = 0;

			m = Multiply(m, m2);
		}
	}

	return m;
}
Matrix Multiply(Matrix x, Matrix y)
{
	Matrix result;

	result.Matrix[0][0] = 0;
	result.Matrix[0][1] = 0;
	result.Matrix[1][0] = 0;
	result.Matrix[1][1] = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int t = 0; t < 2; t++)
				result.Matrix[i][j] += x.Matrix[i][t] * y.Matrix[t][j];
		}
	}

	return result;
}