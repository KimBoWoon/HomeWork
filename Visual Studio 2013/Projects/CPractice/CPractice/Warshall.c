#include <stdio.h>

void warshall(int Marix[4][4], int n);

int main(void)
{
	//�ͼȾ˰����� �����ϱ� ���� ����� ����
	int Matrix[4][4]={
		{0, 1, 0, 0},
		{1, 0, 1, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 0}
	};
	int i, j;
	//�ͼȾ˰����� �����ϱ� ��
	printf("before\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("	%d", Matrix[i][j]);
		printf("\n");
	}

	warshall(Matrix, 4);
	//�ͼȾ˰����� �����ϰ� �� ��
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
	//�ͼȾ˰��� ����
	for (k=0;k<n;k++)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				Matrix[i][j] = Matrix[i][j] | (Matrix[i][k] & Matrix[k][j]);
		}
		//�ͼȾ˰����� ���� ����
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