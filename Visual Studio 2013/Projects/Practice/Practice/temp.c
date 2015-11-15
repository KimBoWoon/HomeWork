#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int testCase;

	scanf("%d", &testCase);

	while (testCase--) {
		int height, width, n;
		scanf("%d %d %d", &height, &width, &n);
		printf("%d%02d\n", (n - 1) % height + 1, (n - 1) / height + 1);
	}
}