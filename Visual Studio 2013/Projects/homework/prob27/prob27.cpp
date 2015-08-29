//20113259	김보운
//문제-27 집합연산

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void Intersection(int *A, int *B, int *arr, int *arr2, int a, int b);
void Union(int *A, int *B, int *arr, int a, int b);
void Minus(int *A, int *B, int *arr, int *arr2, int a, int b);

int main(void)
{
	ifstream inStream;
	int testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		int a, b;
		int A[200]={0}, B[200]={0}, arr[200]={0}, arr2[200]={0};

		inStream>>a;
		for(int j=0;j<a;j++)
			inStream>>A[j];
		inStream>>b;
		for(int j=0;j<b;j++)
			inStream>>B[j];

		Intersection(A, B, arr, arr2, a, b);
		Union(A, B, arr, a, b);
		Minus(A, B, arr, arr2, a, b);
	}
}
void Intersection(int *A, int *B, int *arr, int *arr2, int a, int b)
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
	cout<<cnt<<" ";
	for(i=0;i<cnt;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	for(i=0;i<200;i++)
		arr[i]=0;
}
void Union(int *A, int *B, int *arr, int a, int b)
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
	cout<<count<<" ";
	for(j=0;j<a+b;j++)
	{
		if(j==0)
			cout<<arr[j]<<" ";
		else if(arr[j-1]<arr[j])
			cout<<arr[j]<<" ";
	}
	cout<<endl;
	for(i=0;i<200;i++)
		arr[i]=0;
}
void Minus(int *A, int *B, int *arr, int *arr2, int a, int b)
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
	cout<<count<<" ";
	for(j=0;j<a+h;j++)
	{
		if(arr[j-1]!=arr[j] && arr[j]!=arr[j+1])
			cout<<arr[j]<<" ";
	}
	cout<<endl;
	for(i=0;i<200;i++)
		arr[i]=0;
}
