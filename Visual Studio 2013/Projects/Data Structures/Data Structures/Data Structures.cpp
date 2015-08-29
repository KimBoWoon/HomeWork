#include <iostream>
#include <vector>
using namespace std;

int BSearch(vector<int> v, int frist, int last, int target);

int main()
{
	vector<int> v;

	for(int i=0;i<10;i++)
		v.push_back(i+1);

	cout<<BSearch(v, 0, v.size()-1, 3)<<endl;
	
}
int BSearch(vector<int> v, int frist, int last, int target)
{
	int mid;

	while(frist<last)
	{
		mid=(frist+last)/2;

		if(v[mid]==target)
			return v[mid];
		else
		{
			if(target<v[mid])
				last=mid-1;
			else
				frist=mid+1;
		}
	}
	return -1;
}