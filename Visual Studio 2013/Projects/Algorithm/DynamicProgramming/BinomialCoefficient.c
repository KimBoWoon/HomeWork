//
// Created by bw on 15. 11. 27.
//

#include <stdio.h>
#include <string.h>

#define MAX 30
#define MIN(a, b) ((a)<(b)?(a):(b))

int binCoeff(int B[MAX][MAX], int n, int k) {
    int i, j;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= MIN(i, k); j++)
            if (j == 0 || j == i)
                B[i][j] = 1; /* base case */
            else
                B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
    return B[n][k];
}

int main() {
    int B[MAX][MAX];
    int i, j;

    memset(B, 0, sizeof(int) * MAX * MAX);
    printf("%d\n", binCoeff(B, 20, 15));

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    return 0;
}