//20113259	김보운
//문제-39 절단 대각선

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

int add(const int a[][MAX_SIZE], int n);
int add2(const int a[][MAX_SIZE], int n);
void read(ifstream &inStream, int m[][MAX_SIZE], int n);

void main(void)
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream>>cases;

	for(int i=0;i<cases;i++)
	{
		int A[MAX_SIZE][MAX_SIZE];
		int n;

		inStream>>n;

		read(inStream, A, n);

		if(add(A, n) > add2(A, n))
			cout<<add(A, n)<<endl;
		else
			cout<<add2(A, n)<<endl;
	}
	inStream.close();
}
int add(const int a[][MAX_SIZE], int n)
{
	int result=0;
	int sum = 0, x = 1, y = n-1, z = n-1, m = 1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum += a[j][y];
			y++;
		}
		for(int j=0;j<z;j++)
		{
			sum += a[x][j];
			x++;
		}
		x = m+1;
		y = n-m-1;
		z--;
		m++;

		if(sum>result)
		{
			result = sum;
			sum=0;
		}
		else
			sum=0;
	}

	return result;
}
int add2(const int a[][MAX_SIZE], int n)
{
	int result=0;
	int sum = 0, x = n-1, y = 0, z = n-1, m = 1, h = 1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum += a[y][j];
			y--;
		}
		for(int j=0;j<z;j++)
		{
			sum += a[x][h];
			x--;
			h++;
		}
		y = m;
		h = m+1;
		x = n-1;
		z--;
		m++;

		if(sum>result)
		{
			result = sum;
			sum=0;
		}
		else
			sum=0;
	}

	return result;
}
void read(ifstream &inStream, int m[][MAX_SIZE], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			inStream>>m[i][j];
	}
}