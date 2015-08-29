/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 행렬 곱셈 - 포인터 사용                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int **m, int row, int col);
int **memory(int row, int col);
int **mul(int **data, int **data2, int row, int s, int col);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int **data, **data2;
		int row, col, s;

		fscanf(file, "%d %d %d", &row, &s, &col);

		data=memory(row, s);
		data2=memory(s, col);
		read(file, data, row, s);
		read(file, data2, s, col);
		mul(data, data2, row, s, col);
		free(data);
		free(data2);
	}
	fclose(file);
}
void read(FILE *file, int **m, int row, int col)
{
	int i, j, *arr;

	for(i=0;i<row;i++)
	{
		arr=*(m+i);
		for(j=0;j<col;j++)
			fscanf(file, "%d", arr++);
	}
}
int **memory(int row, int col)
{
	int i, **arr, *m;

	arr=(int **) malloc(sizeof(int *) * row);
	m=(int *) malloc(sizeof(int) * row * col);

	for(i=0;i<row;i++)
	{
		*(arr+i)=m;
		m+=col;
	}
	return arr;
}
int **mul(int **data, int **data2, int row, int s, int col)
{
	int i, j, h;
	int *a, *b, c=0;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{		
			a = *(data+i);
			b = *(data2) + j;
			for(h=0;h<s;h++)
			{
				c += *a++ * *b;
				b += col;
			}
			printf("%d ", c);
			c=0;
		}
		puts("");
	}
}