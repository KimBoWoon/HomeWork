#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
	int size;
	vector<vector<int>> matrix;
public:
	Matrix(int s) : size(s), matrix(size, size)	{}
	void MakeMatrix()
	{
		int cnt=1;

		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				matrix[i][j]=cnt++;
		}
	}
	void PrintMatrix()
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main()
{
	int size;

	cin>>size;

	Matrix matrix(size);

	matrix.MakeMatrix();

	matrix.PrintMatrix();
}