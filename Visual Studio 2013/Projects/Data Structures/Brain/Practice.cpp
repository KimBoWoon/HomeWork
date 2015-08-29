#include <stdio.h>

int tab[1010][1010];
int dist[1010];
int check[1010];
int A[1010];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, k, n, m, l, min, a, b, c, sw;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		tab[a][b] = c;
		if (0 == c) tab[a][b] = 0x7fffffff;
	}
	for (i = 1; i <= n; i++){
		for (k = 1; k <= n; k++){
			if (tab[i][k] == 0x7fffffff) tab[i][k] = 0;
			else if (tab[i][k] == 0) tab[i][k] = 0x7fffffff;
		}
	}
	for (i = 2; i <= n; i++){
		if (tab[1][i] != 0x7fffffff){
			A[i] = 1;
			dist[i] = tab[1][i];
		}
		else{
			A[i] = i;
			dist[i] = tab[1][i];
		}
	}
	A[1] = 1;
	check[1] = 1;
	do{
		min = 0x7fffffff;
		for (i = 1; i <= n; i++){
			if (dist[i] < min && check[i] % 2 == 0){
				min = dist[i];
				l = i;
			}
		}
		check[l] = 1;
		sw = 0;
		for (i = 1; i <= n; i++){
			if (tab[l][i] != 0x7fffffff){
				if (dist[i] > min + tab[l][i]){
					if (A[i] == l) continue;
					A[i] = l;
					check[i] = 0;
					dist[i] = min + tab[l][i];
					sw = 1;
				}
			}
		}
		if (sw == 0) break;
	} while (1);

	for (i = 1; i <= n; i++){
		printf("%d ", dist[i]);
	}

	return 0;
}