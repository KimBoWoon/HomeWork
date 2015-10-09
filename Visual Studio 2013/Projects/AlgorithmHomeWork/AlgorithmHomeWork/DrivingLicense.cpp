//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - Driving License
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
using namespace std;

//매트릭스 동적할당
int** matrixAllocation(int m, int n);
//매트릭스 입력
void matrixInput(ifstream &in, int **mat, int m, int n);
//운전면허 시험
void drivingLicense(int **m1, int **m2, int m, int n, int l, int g);
//매트릭스 동적할당 반환
void deleteMatrix(int** mat, int m);

//0 오른쪽 1 아래
//drivint[row][col][rotate][direction]
int driving[101][101][201][2];

int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int m = 0, n = 0, l = 0, g = 0;
		int rotate = 0;
		int **m1 = NULL;
		int **m2 = NULL;

		in >> m >> n >> l >> g;
		/*for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				for (int z = 0; z < 201; z++) {
					for (int t = 0; t < 2; t++) {
						driving[x][y][z][t] = -1;
					}
				}
			}
		}*/
		memset(driving, -1, sizeof(driving));
		driving[0][0][0][0] = driving[0][0][0][1] = 0;

		m1 = matrixAllocation(m, n);
		m2 = matrixAllocation(m, n);

		matrixInput(in, m1, m, n - 1);
		matrixInput(in, m2, m - 1, n);

		drivingLicense(m1, m2, m, n, l, g);

		deleteMatrix(m1, m);
		deleteMatrix(m2, m);
	}
}
int** matrixAllocation(int m, int n) {
	int **mat = NULL;

	mat = new int*[m];
	for (int x = 0; x < m; x++)
		mat[x] = new int[n];

	return mat;
}
void matrixInput(ifstream &in, int **mat, int m, int n) {
	int temp = 0;

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			in >> temp;
			mat[x][y] = temp;
		}
	}
}
void drivingLicense(int **m1, int **m2, int m, int n, int l, int g) {
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			for (int z = 0; z < 201; z++) {
				if (driving[x][y][z][0] != -1) {
					if (x < m - 1) {
						//이미 값을 가지고 있으면 그 중 작은값을 넣어준다
						if (driving[x + 1][y][z + 1][1] != -1)
							driving[x + 1][y][z + 1][1] = min(driving[x][y][z][0] + m2[x][y], driving[x + 1][y][z + 1][1]);
						//값이 없으면 연료 사용량을 넣어준다
						else
							driving[x + 1][y][z + 1][1] = driving[x][y][z][0] + m2[x][y];
					}
					if (y < n - 1) {
						if (driving[x][y + 1][z][0] != -1)
							driving[x][y + 1][z][0] = min(driving[x][y][z][0] + m1[x][y], driving[x][y + 1][z][0]);
						else
							driving[x][y + 1][z][0] = driving[x][y][z][0] + m1[x][y];
					}
				}
				if (driving[x][y][z][1] != -1) {
					if (x < m - 1) {
						if (driving[x + 1][y][z][1] != -1)
							driving[x + 1][y][z][1] = min(driving[x][y][z][1] + m2[x][y], driving[x + 1][y][z][1]);
						else
							driving[x + 1][y][z][1] = driving[x][y][z][1] + m2[x][y];
					}
					if (y < n - 1) {
						if (driving[x][y + 1][z + 1][0] != -1)
							driving[x][y + 1][z + 1][0] = min(driving[x][y][z][1] + m1[x][y], driving[x][y + 1][z + 1][0]);
						else
							driving[x][y + 1][z + 1][0] = driving[x][y][z][1] + m1[x][y];
					}
				}
			}
		}
	}
	//최적화된 회전횟수를 구한다
	int best = -1;

	for (int x = 0; x < 201; x++) {
		//-1은 할당되지 않은 곳
		//도착지점에서 필요한 가솔린양보다 적으면 최적의 길이다
		//x는 회전횟수를 나타냄
		if (driving[m - 1][n - 1][x][0] != -1 && driving[m - 1][n - 1][x][0] <= g ||
			driving[m - 1][n - 1][x][1] != -1 && driving[m - 1][n - 1][x][1] <= g) {
			best = x;
			break;
		}
	}
	if (best == -1)
		cout << -1 << endl;
	else
		cout << (m + n - 2) * l + best << endl;
}
void deleteMatrix(int** mat, int m) {
	for (int x = 0; x < m; x++)
		delete[] mat[x];
	delete[] mat;
}
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int T, M, N, L, G;
//int H[101][101], V[101][101], D[101][101][2][201];
//
//int main()
//{
//	int testCase;
//	int temp;
//	ifstream in;
//
//	in.open("input.txt");
//
//	in >> testCase;
//
//	for (int i = 0; i < testCase; i++) {
//		in >> N >> M >> L >> G;
//
//		for (int x = 1; x <= N; x++) {
//			for (int y = 1; y < M; y++) {
//				in >> temp;
//				H[x][y] = temp;
//			}
//		}
//		for (int x = 1; x < N; x++) {
//			for (int y = 1; y <= M; y++) {
//				in >> temp;
//				V[x][y] = temp;
//			}
//		}
//		for (int x = 1; x <= N; x++) {
//			for (int y = 1; y <= M; y++) {
//				for (int k = 0; k < 2; k++) {
//					for (int l = 0; l < 201; l++) {
//						D[x][y][k][l] = G + 1;
//					}
//				}
//			}
//		}
//
//		D[1][1][0][0] = D[1][1][1][0] = 0;
//		int ans = 2e9;
//
//		for (int x = 1; x <= N; x++) {
//			for (int y = 1; y <= M; y++) {
//				for (int l = 0; l < 201; l++) {
//					for (int k = 0; k < 2; k++) {
//						if (D[x][y][k][l] <= G) {
//							//printf("%d %d %d %d: %d\n", i, y, k, l, D[i][y][k][l]);
//							if (x == N && y == M) {
//								if (ans > l)
//									ans = l;
//							}
//							if (l < 200 && D[x][y][!k][l + 1] > D[x][y][k][l])
//								D[x][y][!k][l + 1] = D[x][y][k][l];
//							if (k) {
//								if (y < M && D[x][y + 1][k][l] > D[x][y][k][l] + H[x][y])
//									D[x][y + 1][k][l] = D[x][y][k][l] + H[x][y];
//							}
//							else {
//								if (x < N && D[x + 1][y][k][l] > D[x][y][k][l] + V[x][y])
//									D[x + 1][y][k][l] = D[x][y][k][l] + V[x][y];
//							}
//						}
//					}
//				}
//			}
//		}
//		if (ans < 2e9)
//			cout << (N + M - 2) * L + ans << endl;
//		else 
//			puts("-1");
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//#include <fstream>
//using namespace std;
//
//#define MIN(a, b)   (a < b ? (a) : (b))
//
//int dp[100][100][200][2];
//
//int main()
//{
//	int tc;
//	int temp;
//	ifstream in;
//
//	in.open("input.txt");
//
//	in >> tc;
//	//scanf("%d", &tc);
//	while (tc--){
//		int R, C, L, G;
//		in >> R >> C >> L >> G;
//		//scanf("%d %d %d %d", &R, &C, &L, &G);
//
//		int fuel[100][100][2];
//		for (int i = 0; i < R; i++)
//			for (int j = 0; j < (C - 1); j++) {
//				in >> temp;
//				fuel[i][j][0] = temp;
//				//scanf("%d", &fuel[i][j][0]);
//			}
//
//		for (int i = 0; i < (R - 1); i++)
//			for (int j = 0; j < C; j++) {
//				in >> temp;
//				fuel[i][j][1] = temp;
//				//scanf("%d", &fuel[i][j][1]);
//			}
//
//		memset(dp, 0x01, sizeof(dp));
//		dp[0][0][0][0] = dp[0][0][0][1] = 0;
//
//		for (int i = 1; i < R; i++)
//			dp[i][0][0][1] = dp[i - 1][0][0][1] + fuel[i - 1][0][1];
//		for (int i = 1; i < C; i++)
//			dp[0][i][0][0] = dp[0][i - 1][0][0] + fuel[0][i - 1][0];
//
//		for (int i = 1; i < R; i++)
//			for (int j = 1; j < C; j++){
//				int max_turn = MIN(i, j) * 2 - 1;
//				for (int k = 1; k <= 199; k++){
//					dp[i][j][k][0] = MIN(dp[i][j - 1][k][0], dp[i][j - 1][k - 1][1]) + fuel[i][j - 1][0];
//					dp[i][j][k][1] = MIN(dp[i - 1][j][k - 1][0], dp[i - 1][j][k][1]) + fuel[i - 1][j][1];
//				}
//			}
//
//		int ans = -1, max_turn = MIN(R, C) * 2 - 1;
//		for (int i = 0; i <= 199; i++)
//			if (dp[R - 1][C - 1][i][0] <= G || dp[R - 1][C - 1][i][1] <= G){
//				ans = (R + C - 2) * L + i; break;
//			}
//
//		printf("%d\n", ans);
//	}
//	return 0;
//}