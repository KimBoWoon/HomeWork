//20113259	김보운
//문제-04 부활절 날짜계산

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void compute(int y);

void main()
{
	ifstream inStream;
	int y, testnum;

	inStream. open("input.txt");
	if(inStream.fail())
	{
		cerr<<"input File opening failed.\n";
		exit(1);
	}

	inStream>>testnum;

	for(int i=0;i<testnum;i++)
	{
		inStream>>y;
		compute(y);
	}

	inStream.close();
}

void compute(int y)
{
	int c, n, t, i, j, k, l, p, q, o, u, w, r, b, v, x, month, day;

	c=y/100;
	n=y-(y/19)*19;
	t=(c-17)/25;
	o=c-(c/4)-(c-t)/3;
	u=n*19+15;
	i=o+u;
	j=i-(i/30)*30;
	w=j/28;
	r=1-w;
	b=29/(j+1);
	v=(21-n)/11;
	k=j-(w*r*b*v);
	x=y+(y/4)+j+2;
	l=(x-c)+(c/4);
	p=l-(l/7)*7;
	q=k-p;
	month=((q+40)/44)+3;
	day=(q+28)-((month/4)*31);

	std::cout<<month<<' '<<day<<std::endl;
}