//20113259	김보운
//문제-50 숫자의 진법 변환

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
	{	//출력은 제대로 되는대 채점서버에서 점수가 제대로나오지않음
		//이해가 안되는부분 컴퓨터내에서 소수점 연산은 부동소수점연산이라 그런가?????
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