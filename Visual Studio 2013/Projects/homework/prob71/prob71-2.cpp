#include "prob71.h"

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> cases;

	for (int i = 0; i < cases; i++)
	{
		int coordx, coordy;

		inStream >> coordx >> coordy;
		point p1(coordx, coordy);

		inStream >> coordx >> coordy;
		point p2(coordx, coordy);

		if (p1 == p2)
			cout << "1" << " ";
		if (p1 != p2)
			cout << "0" << " ";

		cout << p1.dist2sqr(p2) << " " << p1.dist1(p2) << " ";

		coordx = p1.getx();
		coordy = p1.gety();

		point p3(p1);

		p3.setx(coordy);
		p3.sety(coordx);

		cout << p1.dist2sqr(p3) << " " << p1.dist1(p3) << endl;
	}
	inStream.close();
}