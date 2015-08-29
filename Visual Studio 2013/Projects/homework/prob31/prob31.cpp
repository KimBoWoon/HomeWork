//20113259 김보운
//문제-31 소인수분해
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int compute(int num);
int primenumber(int prime);

int main(void)
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input file opening failde\n";
		exit(1);
	}

	inStream>>cases;

	for(int i=0;i<cases;i++)
	{
		int num, cnt=0, prime=2, primecnt=0;

		inStream>>num;

		cout<<compute(num)<<" ";

		while(num!=1)
		{
			while(num%prime==0)
			{
				num/=prime;
				cnt++;
			}
			if(cnt>=1)
			{
				cout<<prime<<" "<<cnt<<" ";
				cnt=0;
			}
			prime = primenumber(prime);
		}
		cout<<endl;
	}
}
int compute(int num)
{
	int cnt=0, prime=2, primecnt=0;

	while(num!=1)
	{
		while(num%prime==0)
		{
			num/=prime;
			cnt++;
		}
		if(cnt>=1)
		{
			cnt=0;
			primecnt++;
		}
		prime = primenumber(prime);
	}
	return primecnt;
}
int primenumber(int prime)
{
	for(;;)
	{
		int k;
		prime++;
		for(k=2;k<prime;k++)
		{
			if(prime%k==0)
				break;
		}
		if(k==prime)
			break;
	}

	return prime;
}