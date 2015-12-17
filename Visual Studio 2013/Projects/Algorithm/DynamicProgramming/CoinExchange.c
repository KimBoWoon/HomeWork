//
// Created by bw on 15. 11. 27.
//

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define CHANGE 21

int comp(const void* x, const void* y) {
	return *(int*)x - *(int*)y;
}
void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[], int lastCoin[]) {
    int cents, j;
    /* coinsUsed = C, lastCoin = L */
    coinsUsed[0] = lastCoin[0] = 0;
    for (cents = 1; cents <= change; cents++) {
        int minCoins, newCoin;
        minCoins = cents;
        newCoin = 1;
        for (j = 0; j < numDiffCoins; j++) {
            if (coins[j] > cents)
                continue;
            if (coinsUsed[cents - coins[j]] + 1 < minCoins) {
                minCoins = coinsUsed[cents - coins[j]] + 1;
                newCoin = coins[j];
            }
        }
        coinsUsed[cents] = minCoins;
        lastCoin[cents] = newCoin;
    }
}

void reconstruct(int change, int lastCoin[]) {
    if (change > 0) {
        reconstruct(change - lastCoin[change], lastCoin);
        printf("%d ", lastCoin[change]);
    }
}

int main() {
    int coins[] = {1, 5, 10, 21, 25};
    int coinsUsed[CHANGE + 1], lastCoin[CHANGE + 1];
    int i;

	freopen("output.txt", "w", stdout);

	qsort(coins, sizeof(coins) / sizeof(coins[0]), sizeof(coins[0]), comp);

    coinExchange(coins, sizeof(coins) / sizeof(coins[0]), CHANGE, coinsUsed, lastCoin);

    for (i = 0; i < CHANGE + 1; i++)
        printf("%d\t", i);
    printf("\n");
    for (i = 0; i < CHANGE + 1; i++)
        printf("%d\t", coinsUsed[i]);
    printf("\n");
    for (i = 0; i < CHANGE + 1; i++)
        printf("%d\t", lastCoin[i]);
    printf("\n");

    reconstruct(CHANGE, lastCoin);

    return 0;
}