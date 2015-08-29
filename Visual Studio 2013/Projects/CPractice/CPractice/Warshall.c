#include <stdio.h>

void warshall(int Marix[4][4], int n);

int main(void)
{
	//와셜알고리즘을 수행하기 위한 행렬을 만듬
	int Matrix[4][4]={
		{0, 1, 0, 0},
		{1, 0, 1, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 0}
	};
	int i, j;
	//와셜알고리즘을 수행하기 전
	printf("before\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("	%d", Matrix[i][j]);
		printf("\n");
	}

	warshall(Matrix, 4);
	//와셜알고리즘을 수행하고 난 후
	printf("after\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("	%d", Matrix[i][j]);
		printf("\n");
	}
}
void warshall(int Matrix[4][4], int n)
{
	int i, j, k, a, b, cnt=1;
	//와셜알고리즘 수행
	for (k=0;k<n;k++)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				Matrix[i][j] = Matrix[i][j] | (Matrix[i][k] & Matrix[k][j]);
		}
		//와셜알고리즘의 진행 과정
		printf("prove W%d\n", cnt);
		for(a=0;a<4;a++)
		{
			for(b=0;b<4;b++)
				printf("	%d", Matrix[a][b]);
			printf("\n");
		}
		cnt++;
	}
}