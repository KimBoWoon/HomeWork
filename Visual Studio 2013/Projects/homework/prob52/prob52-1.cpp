#include "prob52.h"

BinaryNumber::BinaryNumber() : value(0)
{
}

BinaryNumber::BinaryNumber(unsigned int val) : value(val)
{
}

unsigned int BinaryNumber::getValue() const
{
	return value;
}
void BinaryNumber::setValue(unsigned int val)
{
	value=val;
}

int BinaryNumber::getHammingWeight() const
{
	unsigned int cnt=0, binary;

	for(int i=0;i<31;i++)
	{
		binary=value;
		binary>>=i;

		if((binary & 1)==1)
			cnt++;
	}
	return cnt;
}

int BinaryNumber::getHammingDistance(const BinaryNumber& bn) const
{
	unsigned int cnt=0, binary, binary2;

	for(int i=0;i<31;i++)
	{
		binary=value ^ bn.value;
		binary>>=i;

		if((binary & 1)==1)
			cnt++;
	}
	return cnt;
}