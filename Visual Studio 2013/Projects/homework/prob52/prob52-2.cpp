#include <iostream>
#include <fstream>
#include <cstdlib>
#include "prob52.h"

using namespace std;

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream>>cases;

	for(int i=0;i<cases;i++)
	{
		unsigned int num1, num2;
		inStream>>num1>>num2;

		BinaryNumber bn1(num1), bn2(num2);
		
		cout<<bn1.getHammingWeight()<<" "<<bn2.getHammingWeight()<<" "<<bn1.getHammingDistance(bn2)<<endl;
	}
	inStream.close();
}