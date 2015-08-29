//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//class Third
//{
//private:
//	int size;
//	vector<int> score;
//	vector<char**> name;
//public:
//	Third(int x) : size(x)	{}
//	void Set()
//	{
//		for(int i=0;i<size;i++)
//		{
//			char n[100][100]={NULL};
//			int s;
//			cin>>n[i]>>s;
//			name.push_back(n);
//			score.push_back(s);
//		}
//		for(int i=0;i<size;i++)
//			cout<<name[i]<<" "<<score[i]<<endl;
//	}
//	void Search()
//	{
//		for(int i=0;i<size;i++)
//		{
//			for(int j=0;j<size-1;j++)
//			{
//				if(score[i]>score[j])
//				{
//					int temp=score[i];
//					score[i]=score[j];
//					score[j]=temp;
//					/*char str[100]={NULL};
//					strcpy(str, name[i]);
//					strcpy(name[i], name[j]);
//					strcpy(name[j], str);*/
//				}
//			}
//		}
//		cout<<name[2]<<" "<<score[2]<<endl;
//	}
//};
//
//int main()
//{
//	int size;
//
//	cin>>size;
//
//	Third third(size);
//
//	third.Set();
//
//	third.Search();
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//class Ciphers_Sum
//{
//private:
//	string str;
//public:
//	void SetStr(const char* s)	{	str=s;	}
//	void Calculator()
//	{
//		int sum_one=0;
//
//		for(int i=0;str.size()!=1;i++)
//		{
//			char temp[10]={NULL};
//			sum_one+=str[i]-48;
//			if(i==str.size()-1)
//			{
//				int mul=1, temp_num=sum_one;
//				for(int i=0;temp_num>9;i++)
//				{
//					temp_num/=10;
//					mul*=10;
//				}
//				for(int i=0;mul>0;i++)
//				{
//					temp[i]=sum_one/mul;
//					sum_one%=10;
//					mul/=10;
//				}
//				str.clear();
//				for(int i=0;i<strlen(temp);i++)
//					str.push_back(temp[i]+48);
//				sum_one=0;
//				i=-1;
//			}
//		}
//		cout<<str<<endl;
//	}
//};
//
//int main()
//{
//	int number;
//	char str[10];
//	vector<Ciphers_Sum> arr;
//
//	cin>>number;
//
//	arr.resize(number);
//
//	for(int i=0;i<number;i++)
//	{
//		cin>>str;
//
//		arr[i].SetStr(str);
//	}
//	for(int i=0;i<number;i++)
//		arr[i].Calculator();
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class K_Number
{
private:
	vector<int> question;
	vector<int> answer;
public:
	void SetQuestion(int size)
	{
		int dummy;
		for(int i=0;i<size;i++)
		{
			cin>>dummy;
			question.push_back(dummy);
		}
	}
	void SetAnswer(int size)
	{
		int dummy;
		for(int i=0;i<size;i++)
		{
			cin>>dummy;
			answer.push_back(dummy);
		}
	}
	void Search()
	{
		vector<int>::iterator iter;
		
		for(int i=0;i<answer.size();i++)
		{
			iter=find(question.begin(), question.end(), answer[i]);
			if(iter==question.end())
				cout<<0<<" ";
			else
				cout<<1<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	int size;
	K_Number k_number;

	cin>>size;

	k_number.SetQuestion(size);

	cin>>size;

	k_number.SetAnswer(size);

	k_number.Search();
}

//#include <iostream>
//#include <vector>
//using namespace std;
// 
//class Decodement
//{
//private:
//	int password;
//	vector<int> prime;
//public:
//	void SetPassword()	{	cin>>password;	}
//	bool Decode()
//	{
//		for(int i=2;i<password;i++)
//		{
//			if(Prime(i))
//				prime.push_back(i);
//		}
//		for(int i=0;i<prime.size();i++)
//		{
//			for(int j=0;j<prime.size();j++)
//			{
//				if(prime[i]*prime[j]==password)
//				{
//					cout<<prime[i]<<" "<<prime[j]<<endl;
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	bool Prime(int num)
//	{
//		for(int i=2;i<num;i++)
//		{
//			if(num%i==0)
//				return false;
//		}
//		return true;
//	}
//};
// 
//int main()
//{
//	Decodement decodement;
//
//	decodement.SetPassword();
//
//	if(!decodement.Decode())
//		cout<<"wrong number"<<endl;
//}

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