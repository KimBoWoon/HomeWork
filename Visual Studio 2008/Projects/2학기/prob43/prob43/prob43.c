/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                      집합 연산 (2)                      *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int *arr, int n);
void compute(int *A, int *B, int *arr, int *arr2, int a, int b);
void compute2(int *A, int *B, int *arr, int a, int b);
void compute3(int *A, int *B, int *arr, int *arr2, int a, int b);

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
		int A[200]={0}, B[200]={0}, arr[200]={0}, arr2[200]={0};

		fscanf(file, "%d", &a);
		read(file, A, a);
		fscanf(file, "%d", &b);
		read(file, B, b);

		compute(A, B, arr, arr2, a, b);
		compute2(A, B, arr, a, b);
		compute3(A, B, arr, arr2, a, b);
	}
}
void read(FILE *file, int *arr, int n)
{
	int i;

	for(i=0;i<n;i++)
		fscanf(file, "%d", &arr[i]);
}
void compute(int *A, int *B, int *arr, int *arr2, int a, int b)
{
	int i, j, cnt=0, temp, count=0;

	for(i=0;i<a;i++)
	{
		for(j=0;j<a-1;j++)
		{
			if(A[i]<A[j])
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	for(i=0;i<b;i++)
	{
		for(j=0;j<b-1;j++)
		{
			if(B[i]<B[j])
			{
				temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(A[i]==B[j])
			{
				arr2[cnt]=arr[cnt]=A[i];
				cnt++;
			}
		}
	}
	printf("%d ", cnt);
	for(i=0;i<cnt;i++)
		printf("%d ", arr[i]);
	puts("");
	for(i=0;i<200;i++)
		arr[i]=0;
}
void compute2(int *A, int *B, int *arr, int a, int b)
{
	int i, j, cnt=0, temp, count=0;

	for(i=0;i<a+b;i++)
	{
		if(A[i]!=0)
			arr[i]=A[i];
		else
		{
			arr[i]=B[cnt];
			cnt++;
		}
	}
	for(i=0;i<a+b;i++)
	{
		for(j=0;j<(a+b)-1;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(j=0;j<a+b;j++)
	{
		if(j==0)
			count++;
		else if(arr[j-1]<arr[j])
			count++;
	}
	printf("%d ", count);
	for(j=0;j<a+b;j++)
	{
		if(j==0)
			printf("%d ", arr[j]);
		else if(arr[j-1]<arr[j])
			printf("%d ", arr[j]);
	}
	puts("");
	for(i=0;i<200;i++)
		arr[i]=0;
}
void compute3(int *A, int *B, int *arr, int *arr2, int a, int b)
{
	int i, j, cnt=0, temp, count=0, h=0;

	while(arr2[h]!=0)
		h++;
	for(i=0;i<a+h;i++)
	{
		if(A[i]!=0)
			arr[i]=A[i];
		else
		{
			arr[i]=arr2[cnt];
			cnt++;
		}
	}
	for(i=0;i<a+h;i++)
	{
		for(j=0;j<(a+h)-1;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(j=0;j<a+h;j++)
	{
		if(arr[j-1]!=arr[j] && arr[j]!=arr[j+1])
			count++;
	}
	printf("%d ", count);
	for(j=0;j<a+h;j++)
	{
		if(arr[j-1]!=arr[j] && arr[j]!=arr[j+1])
			printf("%d ", arr[j]);
	}
	puts("");
	for(i=0;i<200;i++)
		arr[i]=0;
}