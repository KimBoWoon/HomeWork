/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*              집합 연산 (1) - 포인터 사용                *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int *read(FILE *file, int n);
int *memory(int size);
void sort(int *m, int size);
void print(int *m, int size);
void intersection(int *A, int *B, int a, int b);
void unions(int *A, int *B, int a, int b);
void difference(int *A, int *B, int a, int b);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int a, b;
		int *A, *B;

		fscanf(file, "%d", &a);
		A=read(file, a);
		fscanf(file, "%d", &b);
		B=read(file, b);

		intersection(A, B, a, b);
		unions(A, B, a, b);
		difference(A, B, a, b);
		free(A);
		free(B);
	}
}
int *read(FILE *file, int n)
{
	int *arr, i;

	arr=memory(n);

	for(i=0;i<n;i++)
		fscanf(file, "%d", &*(arr+i));

	return arr;
}
void intersection(int *A, int *B, int a, int b)
{
	int i, j, cnt=0, size;
	int *intersection;

	size=(a<b) ? a : b;
	intersection = memory(size);

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(*(A+i) == *(B+j))
			{
				*(intersection+cnt)=*(A+i);
				cnt++;
			}
		}
	}
	print(intersection, cnt);
	free(intersection);
}
void unions(int *A, int *B, int a, int b)
{
	int i, j, cnt=0;
	int *unions;

	unions = memory(a+b);

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(*(A+i) == *(B+j))
				*(A+i)=0;
		}
	}
	for(i=0;i<a;i++)
	{
		if(*(A+i) != 0)
		{
			*(unions+cnt)=*(A+i);
			cnt++;
		}
	}
	for(i=0;i<b;i++)
	{
		*(unions+cnt)=*(B+i);
		cnt++;
	}
	print(unions, cnt);
	free(unions);
}
void difference(int *A, int *B, int a, int b)
{
	int i, j, cnt=0;
	int *difference;

	difference=memory(a);

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(*(A+i) == *(B+j))
				*(A+i)=0;
		}
	}
	for(i=0;i<a;i++)
	{
		if(*(A+i) != 0)
		{
			*(difference+cnt)=*(A+i);
			cnt++;
		}
	}
	print(difference, cnt);
	free(difference);
}
int *memory(int size)
{
	int *data;

	data = malloc(size * sizeof(int));

	return data;
}
void print(int *m, int size)
{
	int i;

	printf("%d ", size);

	sort(m, size);

	for(i=0;i<size;i++)
		printf("%d ", *m++);
	puts("");
}
void sort(int *m, int size)
{
	int i, j, temp;

	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(*(m+i) < *(m+j))
			{
				temp = *(m+i);
				*(m+i) = *(m+j);
				*(m+j) = temp;
			}
		}
	}
}