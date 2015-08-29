#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
	int di;
	int co;
}Polynomial;

int main() {
	Polynomial *A;
	Polynomial *B;
	Polynomial *result;
	int ACount = 0, BCount = 0;
	int i = 0, x = 0, y = 0, cnt = 0;

	printf("첫 번째 항의 수를 입력하세요 : ");
	scanf_s("%d", &ACount, sizeof(int));
	A = (Polynomial *)calloc(ACount, sizeof(Polynomial));

	printf("차수와 계수를 입력하세요 : ");
	for (i = 0; i < ACount; i++)
		scanf_s("%d %d", &A[i].di, &A[i].co, sizeof(int));

	printf("두 번째 항의 수를 입력하세요 : ");
	scanf_s("%d", &BCount, sizeof(int));
	B = (Polynomial *)calloc(ACount, sizeof(Polynomial));

	printf("차수와 계수를 입력하세요 : ");
	for (i = 0; i < BCount; i++)
		scanf_s("%d %d", &B[i].di, &B[i].co, sizeof(int));

	result = (Polynomial *)calloc(ACount + BCount, sizeof(Polynomial));
	while (x < ACount && y < BCount) {
		if (A[x].di == B[y].co) {
			result[cnt].di = A[x].di;
			result[cnt++].co = A[x++].co + B[y++].co;
		}
		else if (A[x].di > B[y].di) {
			result[cnt].di = A[x].di;
			result[cnt++].co = A[x++].co;
		}
		else {
			result[cnt].di = B[y].di;
			result[cnt++].co = B[y++].co;
		}
	}
	for (; x < ACount;) {
		result[cnt].di = A[x].di;
		result[cnt++].co = A[x++].co;
	}
	for (; y < BCount;) {
		result[cnt].di = B[y].di;
		result[cnt++].co = B[y++].co;
	}

	for (i = 0; i < cnt; i++)
		(i == (cnt - 1)) ? printf("%d %d\n", result[i].di, result[i].co) : printf("%d %d ", result[i].di, result[i].co);

	free(A);
	free(B);
	free(result);
	A = B = result = NULL;
}