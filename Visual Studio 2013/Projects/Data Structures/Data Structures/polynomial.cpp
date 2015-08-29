#include <iostream>
using namespace std;

void merge(int *X, int *Y, int *Z, int m, int n)
{
	int i = 0, j = 0, k = 0;
	while ((i < m) && (j < n)) {
		if (X[i] == Y[j]) {
			Z[k++] = X[i++];
			Z[k++] = Y[j++];
		}
		else if (X[i] > Y[j]) {
			Z[k++] = Y[j++];
		}
		else {
			Z[k++] = X[i++];
		}
	}
	for (; i < m; i++, k++)
		Z[k] = X[i];
	for (; j < n; j++, k++)
		Z[k] = Y[j];
}
int main()
{
	int a[10] = { 1, 2, 4, 5, 7, 8, 9, 10, 12, 14 };
	int b[5] = { 2, 3, 4, 5, 6 };
	int c[15] = { 0 };

	merge(a, b, c, 10, 5);

	for (int i = 0; i < 15; i++)
		cout << c[i] << " ";
	cout << endl;
}