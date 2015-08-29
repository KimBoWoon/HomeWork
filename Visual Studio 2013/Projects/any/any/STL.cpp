#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	vector<int>::iterator iter;

	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(2);

	for(int i=0;i<arr.size()*2;i++)
	{
		iter=find(arr.begin(), arr.end(), i);
		if(iter==arr.end())
			cout<<i<<"는 존재하지 않는 원소"<<endl;
		else
			cout<<i<<"는 존재하는 원소"<<endl;
	}
}