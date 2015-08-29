/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 행렬 덧셈 - 포인터 사용                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int **m, int row, int col);
int **memory(int row, int col);
int **add(int **data, int **data2, int row, int col);

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
		int row, col;

		fscanf(file, "%d %d", &row, &col);

		data=memory(row, col);
		data2=memory(row, col);
		read(file, data, row, col);
		read(file, data2, row, col);
		add(data, data2, row, col);
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
int **add(int **data, int **data2, int row, int col)
{
	int i, j;
	int *a, *b, c;

	for(i=0;i<row;i++)
	{
		a = *(data+i);
		b = *(data2+i);
		for(j=0;j<col;j++)
		{
			c = *a++ + *b++;
			printf("%d ", c++);
			c=0;
		}
		puts("");
	}
}