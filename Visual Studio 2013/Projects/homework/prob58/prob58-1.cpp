#include <cstdlib>
#include "prob58.h"

char readnumber::digits[10][max_length]={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char readnumber::teens[20][max_length]={"", "", "", "", "", "", "", "", "", "", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char readnumber::ties[10][max_length]={"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char readnumber::units[4][max_length]={"Hundred", "Thousand", "Million", "Billion"};

readnumber::readnumber() : number(1)
{
}

readnumber::readnumber(unsigned int num) : number(num)
{
}

void readnumber::setnumber(unsigned int num)
{
	number=num;
}
void readnumber::read() const
{
	unsigned int len=0, temp=number, num[4]={0};

	for(int i=0;temp!=0;i++)
	{
		num[i]=temp%1000;
		temp/=1000;
	}
	if(num[3]!=0)
	{
		for(int i=0;digits[num[3]][i]!=0;i++)
			cout<<digits[num[3]][i];
		cout<<'_';
		for(int i=0;units[3][i]!=0;i++)
			cout<<units[3][i];
		if(num[0]!=0 || num[1]!=0 || num[2]!=0)
			cout<<'_';
	}
	if(num[2]!=0)
	{
		if(num[2]>99)
		{
			for(int i=0;digits[num[2]/100][i]!=0;i++)
				cout<<digits[num[2]/100][i];
			cout<<'_';
			for(int i=0;units[0][i]!=0;i++)
				cout<<units[0][i];
			cout<<'_';
			if(num[2]%100!=0)
			{
				if(num[2]%100>=10 && num[2]%100<20)
				{
					for(int i=0;teens[num[2]%100][i]!=0;i++)
						cout<<teens[num[2]%100][i];
					cout<<'_';
					for(int i=0;units[2][i]!=0;i++)
						cout<<units[2][i];
					if(num[0]!=0 || num[1]!=0)
						cout<<'_';
				}
				else if(num[2]%100>=20)
				{
					for(int i=0;ties[(num[2]/10)%10][i]!=0;i++)
						cout<<ties[(num[2]/10)%10][i];
					cout<<'_';
					if(num[2]%10>0)
					{
						for(int i=0;digits[num[2]%10][i]!=0;i++)
							cout<<digits[num[2]%10][i];
						cout<<'_';
					}
					for(int i=0;units[2][i]!=0;i++)
						cout<<units[2][i];
					if(num[0]!=0 || num[1]!=0)
						cout<<'_';
				}
				else if(num[2]%10>0)
				{
					for(int i=0;digits[num[2]%10][i]!=0;i++)
						cout<<digits[num[2]%10][i];
					cout<<'_';
					for(int i=0;units[2][i]!=0;i++)
						cout<<units[2][i];
					if(num[0]!=0 || num[1]!=0)
						cout<<'_';
				}
			}
			else if(num[2]%100==0)
			{
				for(int i=0;units[2][i]!=0;i++)
					cout<<units[2][i];
				if(num[0]!=0 || num[1]!=0)
					cout<<'_';
			}
		}
		else if(num[2]>9)
		{
			if(num[2]%100!=0)
			{
				if(num[2]%100>=10 && num[2]%100<20)
				{
					for(int i=0;teens[num[2]%100][i]!=0;i++)
						cout<<teens[num[2]%100][i];
					cout<<'_';
					for(int i=0;units[2][i]!=0;i++)
						cout<<units[2][i];
					if(num[0]!=0 || num[1]!=0)
						cout<<'_';
				}
				else if(num[2]%100>=20)
				{
					for(int i=0;ties[(num[2]/10)%10][i]!=0;i++)
						cout<<ties[(num[2]/10)%10][i];
					cout<<'_';
					if(num[2]%10>0)
					{
						for(int i=0;digits[num[2]%10][i]!=0;i++)
							cout<<digits[num[2]%10][i];
						cout<<'_';
					}
					for(int i=0;units[2][i]!=0;i++)
						cout<<units[2][i];
					if(num[1]!=0 || num[0]!=0)
						cout<<'_';
				}
			}
		}
		else if(num[2]>0)
		{
			for(int i=0;digits[num[2]%10][i]!=0;i++)
				cout<<digits[num[2]%10][i];
			cout<<'_';
			for(int i=0;units[2][i]!=0;i++)
				cout<<units[2][i];
			if(num[0]!=0 || num[1]!=0)
				cout<<'_';
		}
	}
	if(num[1]!=0)
	{
		if(num[1]>99)
		{
			for(int i=0;digits[num[1]/100][i]!=0;i++)
				cout<<digits[num[1]/100][i];
			cout<<'_';
			for(int i=0;units[0][i]!=0;i++)
				cout<<units[0][i];
			cout<<'_';
			if(num[1]%100!=0)
			{
				if(num[1]%100>=10 && num[1]%100<20)
				{
					for(int i=0;teens[num[1]%100][i]!=0;i++)
						cout<<teens[num[1]%100][i];
					cout<<'_';
					for(int i=0;units[1][i]!=0;i++)
						cout<<units[1][i];
					if(num[0]!=0)
						cout<<'_';
				}
				else if(num[1]%100>=20)
				{
					for(int i=0;ties[(num[1]/10)%10][i]!=0;i++)
						cout<<ties[(num[1]/10)%10][i];
					cout<<'_';
					if(num[1]%10>0)
					{
						for(int i=0;digits[num[1]%10][i]!=0;i++)
							cout<<digits[num[1]%10][i];
						if(num[0]!=0)
						cout<<'_';
					}
					for(int i=0;units[1][i]!=0;i++)
						cout<<units[1][i];
					if(num[0]!=0)
						cout<<'_';
				}
				else if(num[1]%10>0)
				{
					for(int i=0;digits[num[1]%10][i]!=0;i++)
						cout<<digits[num[1]%10][i];
					cout<<'_';
					for(int i=0;units[1][i]!=0;i++)
						cout<<units[1][i];
					if(num[0]!=0)
						cout<<'_';
				}
			}
			else if(num[1]%100==0)
			{
				for(int i=0;units[1][i]!=0;i++)
					cout<<units[1][i];
				if(num[0]!=0)
					cout<<'_';
			}
		}
		else if(num[1]>9)
		{
			if(num[1]%100!=0)
			{
				if(num[1]%100>=10 && num[1]%100<20)
				{
					for(int i=0;teens[num[1]%100][i]!=0;i++)
						cout<<teens[num[1]%100][i];
					cout<<'_';
					for(int i=0;units[1][i]!=0;i++)
						cout<<units[1][i];
					if(num[0]!=0)
						cout<<'_';
				}
				else if(num[1]%100>=20)
				{
					for(int i=0;ties[(num[1]/10)%10][i]!=0;i++)
						cout<<ties[(num[1]/10)%10][i];
					cout<<'_';
					if(num[1]%10>0)
					{
						for(int i=0;digits[num[1]%10][i]!=0;i++)
							cout<<digits[num[1]%10][i];
						if(num[0]!=0)
							cout<<'_';
					}
					for(int i=0;units[1][i]!=0;i++)
						cout<<units[1][i];
					if(num[0]!=0)
						cout<<'_';
				}
			}
		}
		else if(num[1]>0)
		{
			for(int i=0;digits[num[1]%10][i]!=0;i++)
				cout<<digits[num[1]%10][i];
			cout<<'_';
			for(int i=0;units[1][i]!=0;i++)
				cout<<units[1][i];
			if(num[0]!=0)
				cout<<'_';
		}
	}
	if(num[0]!=0)
	{
		if(num[0]>99)
		{
			for(int i=0;digits[num[0]/100][i]!=0;i++)
				cout<<digits[num[0]/100][i];
			cout<<'_';
			for(int i=0;units[0][i]!=0;i++)
				cout<<units[0][i];
			if(num[0]%100!=0)
			{
				cout<<'_';

				if(num[0]%100>=10 && num[0]%100<20)
				{
					for(int i=0;teens[num[0]%100][i]!=0;i++)
						cout<<teens[num[0]%100][i];
				}
				else if(num[0]%100>=20)
				{
					for(int i=0;ties[(num[0]/10)%10][i]!=0;i++)
						cout<<ties[(num[0]/10)%10][i];
					if(num[0]%10>0)
					{
						cout<<'_';
						for(int i=0;digits[num[0]%10][i]!=0;i++)
							cout<<digits[num[0]%10][i];
					}
				}
				else if(num[0]%10>0)
				{
					for(int i=0;digits[num[0]%10][i]!=0;i++)
						cout<<digits[num[0]%10][i];
				}
			}
		}
		else if(num[0]>9)
		{
			if(num[0]%100!=0)
			{
				if(num[0]%100>=10 && num[0]%100<20)
				{
					for(int i=0;teens[num[0]%100][i]!=0;i++)
						cout<<teens[num[0]%100][i];
				}
				else if(num[0]%100>=20)
				{
					for(int i=0;ties[(num[0]/10)%10][i]!=0;i++)
						cout<<ties[(num[0]/10)%10][i];
					if(num[0]%10>0)
					{
						cout<<'_';
						for(int i=0;digits[num[0]%10][i]!=0;i++)
							cout<<digits[num[0]%10][i];
					}
				}
			}
		}
		else if(num[0]>0)
		{
			for(int i=0;digits[num[0]%10][i]!=0;i++)
				cout<<digits[num[0]%10][i];
		}
	}
	cout<<endl;
}