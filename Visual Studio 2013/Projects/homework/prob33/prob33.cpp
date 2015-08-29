//20113259	±èº¸¿î
//¹®Á¦-33 Çà·Ä µ¡¼À

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

void add(const int a[][MAX_SIZE], const int b[][MAX_SIZE], int c[][MAX_SIZE], int row, int col);
void read(ifstream &inStream, int m[][MAX_SIZE], int row, int col);
void print(const int m[][MAX_SIZE], int row, int col);

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
		int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
		int row, col;

		inStream>>row>>col;

		read(inStream, A, row, col);
		read(inStream, B, row, col);
		add(A, B, C, row, col);
		print(C, row, col);
	}
	inStream.close();
}
void add(const int a[][MAX_SIZE], const int b[][MAX_SIZE], int c[][MAX_SIZE], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			c[i][j] = a[i][j] + b[i][j];
	}
}
void read(ifstream &inStream, int m[][MAX_SIZE], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			inStream>>m[i][j];
	}
}
void print(const int m[][MAX_SIZE], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<m[i][j]<<" ";

		cout<<endl;
	}
}