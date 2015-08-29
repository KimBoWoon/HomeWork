#include "prob73.h"

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed\n";
		exit(1);
	}

	inStream>>cases;

	for(int i=0;i<cases;i++)
	{
		int p1x, p2x, p3x, p1y, p2y, p3y;
		int qx, qy;

		inStream>>p1x>>p1y>>p2x>>p2y>>p3x>>p3y;
		inStream>>qx>>qy;

		point p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y);
		point q(qx, qy);
		triangle tri(p1, p2, p3);

		if(tri.gettype1()==0 || tri.gettype2()==0)
			cout<<"0"<<endl;
		else
		{
			cout<<tri.getarea2()<<" "<<tri.gettype2()<<" "<<tri.gettype1()<<" ";
			if(tri.isinside(q))
				cout<<"1"<<endl;
			else if(tri.isonboundary(q))
				cout<<"2"<<endl;
			else if(tri.isoutside(q))
				cout<<"3"<<endl;
		}
	}
	inStream.close();
}