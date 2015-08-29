/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                        밴드 행렬                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int matrix[][100], int n);
int compute(int matrix[][100], int band1, int band2, int n);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int matrix[100][100]={0};
		int n, band1, band2;

		fscanf(file, "%d", &n);

		read(file, matrix, n);

		fscanf(file, "%d %d", &band1, &band2);

		printf("%d\n", compute(matrix, band1, band2, n));
	}
}
void read(FILE *file, int matrix[][100], int n)
{
	int i, j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			fscanf(file, "%d", &matrix[i][j]);
	}
}
int compute(int matrix[][100], int band1, int band2, int n)
{
	int i, j, sum=0, t, k;

	for(i=band1;i<=band2;i++)
	{
		t=band1;

		if(t>=0)
		{
			for(j=0,k=t;j<n-t;k++)
			{
				sum+=matrix[j][k];
				j++;
			}

		}
		else
		{
			t=abs(band1);

			for(j=t,k=0;j<n;j++)
			{
				sum+=matrix[j][k];
				k++;
			}
		}
		band1++;
	}
	return sum;
}