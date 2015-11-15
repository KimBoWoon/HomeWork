#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int dfibo(int n) {
	int *table = (int*)calloc(n + 1, sizeof(n));
	int result;

	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];

	result = table[n];
	free(table);
	return result;
}

int rfibo(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;

	return rfibo(n - 1) + rfibo(n - 2);
}

int main() {
	LARGE_INTEGER start_time, finish_time, liFrequency;

	QueryPerformanceFrequency(&liFrequency);

	QueryPerformanceCounter(&start_time);
	printf("%d\n", dfibo(35));
	QueryPerformanceCounter(&finish_time);

	printf("Time : %f\n", (double)(finish_time.QuadPart - start_time.QuadPart) / (double)liFrequency.QuadPart);
}