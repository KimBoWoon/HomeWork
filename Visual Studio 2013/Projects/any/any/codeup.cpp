#include <iostream>
#include <vector>
using namespace std;

class Super_Sum
{
private:
	int start, end, sum;
	vector<bool> v;
public:
	Super_Sum() : sum(0)	{	cin>>start>>end;	}
	void compute()
	{
		v.resize(5000);
		for(int i=start;i<end;i++)
		{
			int temp=(i%10)+((i/10)%10)+((i/100)%10)+(i/1000)+i;
			if(temp<end)
				v[temp]=true;
		}
		for(int i=start;i<end;i++)
		{
			if(!v[i])
			{
				cout<<i<<" ";
				sum+=i;
			}
		}
		cout<<sum<<endl;
	}
};

int main()
{
	Super_Sum super_sum;

	super_sum.compute();
}