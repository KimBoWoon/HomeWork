#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int comp(const int* x, const int* y) {
	return *(int*)x - *(int*)y;
}

int main() {
	int coin[] = { 10, 50, 100, 500, 1000, 5000, 10000, 50000 };
	int size = sizeof(coin) / sizeof(coin[0]);
	int money;

	scanf("%d", &money);

	qsort(coin, size, sizeof(coin[0]), comp);

	while (money > 0) {
		if (money - coin[size - 1] >= 0) {
			printf("%d ", coin[size - 1]);
			money -= coin[size - 1];
		}
		else if (size == 1 && money - coin[size - 1] < 0) {
			printf("Fail");
			break;
		}
		else if (coin[size - 1] > money) {
			size--;
		}
	}
	printf("\n");
}