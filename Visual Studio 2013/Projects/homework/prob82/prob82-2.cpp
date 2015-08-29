#include "prob82.h"

void testsimplecase();
void testdatafromfile();
void sortdates(rational rationals[], int n);

void main()
{
	testsimplecase();
	testdatafromfile();
}

void testsimplecase()
{
	rational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;

	cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
	cout << frac1.getnumerator() << " " << frac1.getdenominator() << endl;

	cout << frac1*frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;

	cout << ((frac1<frac2) ? 1 : 0) << " " << ((frac1 <= frac2) ? 1 : 0) << " " << ((frac1>frac2) ? 1 : 0) << " " << ((frac1 >= frac2) ? 1 : 0) << " " << ((frac1 == frac2) ? 1 : 0) << " " << ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2<frac3) ? 1 : 0) << " " << ((frac2 <= frac3) ? 1 : 0) << " " << ((frac2>frac3) ? 1 : 0) << " " << ((frac2 >= frac3) ? 1 : 0) << " " << ((frac2 == frac3) ? 1 : 0) << " " << ((frac2 != frac3) ? 1 : 0) << endl;

	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;

	cout << -frac6 << endl;

	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testdatafromfile()
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
		int j, numdata;

		rational rationals[MAX_SIZE];

		inStream >> numdata;

		for (j = 0; j < numdata; j++)
			inStream >> rationals[j];

		sortdates(rationals, numdata);
		for (j = 0; j<numdata; j++)
			cout << rationals[j] << " ";
		cout << endl;
	}
	inStream.close();
}
void sortdates(rational rationals[], int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (rationals[j]>rationals[j + 1])
				swap(rationals[j], rationals[j + 1]);
		}
	}
}