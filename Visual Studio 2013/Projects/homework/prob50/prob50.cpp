//20113259	�躸��
//����-50 ������ ���� ��ȯ

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int compute_s_to_10(const int s, char n[]);
void compute_10_to_t(unsigned int dec, const int t);
void print(char arr[], int i);

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
		int s, t;
		char n[33]={0};

		inStream>>s>>n>>t;

		compute_10_to_t(compute_s_to_10(s, n), t);
	}
	inStream.close();
}
int compute_s_to_10(const int s, char n[])
{
	unsigned int result=0;
	int cnt=strlen(n), mul=1;

	for(int i=0;i<cnt;i++)
	{	//����� ����� �Ǵ´� ä���������� ������ ����γ���������
		//���ذ� �ȵǴºκ� ��ǻ�ͳ����� �Ҽ��� ������ �ε��Ҽ��������̶� �׷���?????
		/*if(n[cnt-i-1] >= 48 && n[cnt-i-1] <= 57)
			result += (n[cnt-i-1]-48) *  pow((float)s, (float)i);
		else
			result += (n[cnt-i-1]-87) * pow((float)s, (float)i);*/
		if(n[cnt-i-1] >= 48 && n[cnt-i-1] <= 57)
			result += (n[cnt-i-1]-48) * (mul);
		else
			result += (n[cnt-i-1]-87) * (mul);
		mul*=s;
	}

	return result;
}
void compute_10_to_t(unsigned int dec, const int t)
{
	char arr[33]={0};
	int i;

	for(i=0;dec>0;i++)
	{
		arr[i]=dec%t;
		dec/=t;
	}
	
	print(arr, i-1);
}
void print(char arr[], int i)
{
	char arr2[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	for(;i>=0;i--) 
		cout<<arr2[arr[i]];
	cout<<endl;
}