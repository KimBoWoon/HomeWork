#include <stdio.h>
#include <stdlib.h>

void Up(int arr[], int* size);
void Factorial(int arr[], int num, int* size);
int SumFactorial(int arr[], int from, int to);
void MultiFactorial(int arr1[], int arr2[], int value[], int* size1, int* size2, int* size);
void PrintNum(int arr[], int size1, int size2);

void main (void)
{
	FILE *fp = fopen("input.txt", "r");
	int i, cases;

	fscanf(fp, "%d", &cases);

	for(i=0; i<cases; i++)
	{
		int size=1, size1=0, size2=0, from, to, value[10001]={0}, num1[10001]={0}, num2[10001]={0};

		fscanf(fp, "%d %d", &from, &to);
		size1 = SumFactorial(num1, from, to);

		fscanf(fp, "%d %d", &from, &to);
		size2 = SumFactorial(num2, from, to);

		MultiFactorial(num1, num2, value, &size1, &size2, &size);

		PrintNum(value, size1, size2);
	}
}

void Up(int arr[], int* size)
{
	int i;

	for(i=0; i<10000; i++) // ¿©±â°¡ ½ÉÈ÷ ¸¾¿¡ ¾Èµë...
		if(arr[i] >= 1000)
		{
			arr[i+1] += arr[i] / 1000, arr[i] %= 1000;

			if(i == *size-1)
				(*size)++;
		}
}

void Factorial(int arr[], int num, int* size)
{
	int i, j;

	for(i=1; i<num; i++)
	{
		for(j=0; j<*size; j++)
			arr[j] *= i;

		Up(arr, size);
	}
}

int SumFactorial(int arr[], int from, int to)
{
	int i, j, size=1;
	arr[0] = to;

	for(i=to-1; i!=from-1; i--)
	{
		for(j=0; j<size; j++)
			arr[j] = (((j==0)? 1 : 0) + arr[j])*i;

		Up(arr, &size);
	}

	Factorial(arr, from, &size);

	return size;
}

void MultiFactorial(int arr1[], int arr2[], int value[], int* size1, int* size2, int* size)
{
	int i, j;

	for(i=0; i<*size1; i++)
	{
		for(j=0; j<*size2; j++)
			value[i+j] += arr1[i] * arr2[j];
		Up(value, size);
	}
}

void PrintNum(int arr[], int size1, int size2)
{
	int i, count=0;
	for(i=0; size1+size2-i != -1; i++)
		if(arr[size1+size2-i] == 0 && count == 0);
		else if(count == 0)
			printf("%d", arr[size1+size2-i]), count++;
		else
			printf("%03d", arr[size1+size2-i]);
		printf("\n");
}