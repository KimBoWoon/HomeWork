//
// Created by bw on 15. 11. 24.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define VERTEX_COUNT 5
#define INF 999999999

typedef struct edge {
	int start;
	int end;
	int weight;
} Edge;

void dijkstra(int arr[][SIZE], int touch[SIZE], int length[SIZE], Edge selectEdge[VERTEX_COUNT]);

void edgePrint(int start, int length[SIZE]);

int main() {
	int arr[SIZE][SIZE] = {
		0, 0, 0, 0, 0, 0,
		0, INF, 7, 4, 6, 1,
		0, INF, INF, INF, INF, INF,
		0, INF, 2, INF, 5, INF,
		0, INF, 3, INF, INF, INF,
		0, INF, INF, INF, 1, INF
	};
	int touch[SIZE] = { 0 };
	int length[SIZE] = { 0 };
	Edge selectEdge[VERTEX_COUNT] = { 0, 0, 0 };

	dijkstra(arr, touch, length, selectEdge);
	edgePrint(1, length);

	return 0;
}

void dijkstra(int arr[][SIZE], int touch[SIZE], int length[SIZE], Edge selectEdge[VERTEX_COUNT]) {
	int i, selectVertexCnt = 0;

	for (i = 1; i < SIZE; i++) {
		touch[i] = 1;
		length[i] = arr[1][i];
	}

	while (selectVertexCnt < VERTEX_COUNT) {
		int min = 999999999;
		int vnear = 0;

		for (i = 2; i < SIZE; i++) {
			if (length[i] >= 0 && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		}

		selectEdge[selectVertexCnt].start = touch[vnear];
		selectEdge[selectVertexCnt].end = vnear;
		selectEdge[selectVertexCnt].weight = length[vnear];
		selectVertexCnt++;

		for (i = 2; i < SIZE; i++) {
			if (length[vnear] + arr[vnear][i] < length[i]) {
				length[i] = length[vnear] + arr[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] *= -1;
	}
}

void edgePrint(int start, int length[SIZE]) {
	int i;

	printf("Single-Source Shortest Paths\n");
	printf("Dijkstra's Algorithm\n");
	printf("Start Vertex : %d\n", start);
	for (i = 1; i < SIZE; i++)
		printf("%d : %d\n", i, abs(length[i]));
}

#include <cstdio>

#define SIZE 1001
#define INF 1000000000

int a[SIZE][SIZE], visit[SIZE], dist[SIZE];
int start, end, n, m;

void dijkstra() {
	int i, j;
	int min;
	int v;

	dist[start] = 0;

	for (i = 1; i <= n; i++) {
		min = INF;

		for (j = 1; j <= n; j++) {
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;

		for (j = 1; j <= n; j++) {
			if (dist[j] > dist[v] + a[v][j])
				dist[j] = dist[v] + a[v][j];
		}
	}
}


int main(void) {
	int from, to, w;

	scanf("%d %d", &n, &m);

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			a[x][y] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);
		scanf("%d", &a[from][to]);
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	scanf("%d %d", &start, &end);

	dijkstra();

	printf("%d \n", dist[end]);

	return 0;
}