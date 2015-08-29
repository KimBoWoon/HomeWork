#include "prob72.h"

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
		int p1x, p2x, p3x, p4x, p1y, p2y, p3y, p4y;

		inStream>>p1x>>p1y>>p2x>>p2y>>p3x>>p3y>>p4x>>p4y;

		point p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y), p4(p4x, p4y);
		linesegment line1(p1, p2);
		linesegment line2(p3, p4);

		if(line1.properintersection(line2) || line2.properintersection(line1))
			cout<<"1"<<endl;
		else if(line1.improperintersection(line2) || line2.improperintersection(line1))
			cout<<"2"<<endl;
		else
			cout<<"0"<<endl;
	}
	inStream.close();
}