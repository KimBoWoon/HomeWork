#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX(x, y) (x > y) ? (x) : (y)

typedef struct table {
	int **table;
}LCSTable;

int rLCS(const char s1[], const char s2[], const int i, const int j, const LCSTable* const table) {
	if (i == 0 || j == 0) {
		table->table[i][j] = 0;
		return table->table[i][j];
	}
	else if (s1[i - 1] == s2[j - 1]) {
		table->table[i][j] = rLCS(s1, s2, i - 1, j - 1, table) + 1;
		return table->table[i][j];
	}
	else {
		int A = rLCS(s1, s2, i - 1, j, table);
		int B = rLCS(s1, s2, i, j - 1, table);

		table->table[i][j] = MAX(A, B);

		return table->table[i][j];
	}
}

int dLCS(const char s1[], const char s2[], const int i, const int j, const LCSTable* const table) {
	int r, c;

	for (r = 1; r <= i; r++) {
		for (c = 1; c <= j; c++) {
			if (s1[r - 1] == s2[c - 1])
				table->table[r][c] = table->table[r - 1][c - 1] + 1;
			else {
				if (table->table[r][c - 1] >= table->table[r - 1][c])
					table->table[r][c] = table->table[r][c - 1];
				else
					table->table[r][c] = table->table[r - 1][c];
			}
		}
	}
	return table->table[i][j];
}

void LCSTraceBack(const char s1[], const char s2[], const int i, const int j, const LCSTable* const table, const char* const str) {
	if (i == 0 || j == 0)
		return;
	
	if (table->table[i][j] > table->table[i][j - 1] &&
		table->table[i][j] > table->table[i - 1][j] &&
		table->table[i][j] > table->table[i - 1][j - 1]) {
		char temp[100];
		strcpy(temp, str);
		sprintf(str, "%c%s", s1[i - 1], temp);
		LCSTraceBack(s1, s2, i - 1, j - 1, table, str);
	}
	else if (table->table[i][j] > table->table[i - 1][j] &&
		table->table[i][j] == table->table[i][j - 1]) {
		LCSTraceBack(s1, s2, i, j - 1, table, str);
	}
	else
		LCSTraceBack(s1, s2, i - 1, j, table, str);
}

void printTable(const LCSTable t, const int s1Size, const int s2Size) {
	int x, y;
	for (x = 0; x < s1Size; x++) {
		for (y = 0; y < s2Size; y++)
			printf("%d ", t.table[x][y]);
		printf("\n");
	}
}

int main() {
	LARGE_INTEGER start_time, finish_time, liFrequency;
	char s1[] = "GOOD MORNING.";
	char s2[] = "GUTEN MORGEN.";
	char* result = NULL;
	int s1Size = strlen(s1) + 1;
	int s2Size = strlen(s2) + 1;
	int length;
	LCSTable t;

	QueryPerformanceFrequency(&liFrequency);

	t.table = (int**)calloc(s1Size, s1[0]);
	for (int i = 0; i < s1Size; i++)
		t.table[i] = (int*)calloc(s2Size, s2[0]);

	QueryPerformanceCounter(&start_time);
	//length = rLCS(s1, s2, s1Size - 1, s2Size - 1, &t);
	length = dLCS(s1, s2, s1Size - 1, s2Size - 1, &t);
	QueryPerformanceCounter(&finish_time);

	printTable(t, s1Size, s2Size);
	result = (char*)calloc(sizeof(t.table[s1Size][s2Size] + 1), sizeof(char));
	LCSTraceBack(s1, s2, s1Size - 1, s2Size - 1, &t, result);

	printf("LCS : %s\n", result);
	printf("Length : %d\n", length);
	printf("Time : %f\n", (double)(finish_time.QuadPart - start_time.QuadPart) / (double)liFrequency.QuadPart);
}