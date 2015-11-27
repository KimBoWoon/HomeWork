//
// Created by bw on 15. 11. 27.
//

#include <stdio.h>

#define MAX_COINS 101
#define MAX_CHANGE 1001

int countCoinExchange(int N[MAX_COINS][MAX_CHANGE], int coins[], int numDiffCoins, int change) {
    int i, j, numComb;

    /* base cases */
    for (i = 0; i <= numDiffCoins; i++)
        N[i][0] = 1;
    for (i = 1; i <= change; i++)
        N[0][i] = 0;
    for (i = 1; i <= numDiffCoins; i++) {
        for (j = 1; j <= change; j++) {
            if (j - coins[i - 1] < 0) /* base case */
                numComb = 0;
            else
                numComb = N[i][j - coins[i - 1]];
            N[i][j] = N[i - 1][j] + numComb;
        }
    }
    return N[numDiffCoins][change];
}

int main() {
    int N[MAX_COINS][MAX_CHANGE] = {0};
    int coins[] = {1, 2, 3, 5};
    int change = 7, i, j;
    int size = sizeof(coins) / sizeof(coins[0]);

    printf("%d\n", countCoinExchange(N, coins, size, change));

    for (i = 0; i <= size; i++) {
        for (j = 0; j <= change; j++)
            printf("%d ", N[i][j]);
        printf("\n");
    }

    return 0;
}