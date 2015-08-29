#include "prob54.h"

IPV4::IPV4() : addNumber(0)
{
	num2address();
}

IPV4::IPV4(unsigned int num) : addNumber(num)
{
	num2address();
}

IPV4::IPV4(unsigned int *add) : addNumber(0)
{
	string2address(add);
}
void IPV4::printAddress() const
{
	cout << address[0] << '.' << address[1] << '.' << address[2] << '.' << address[3] << endl;
}
void IPV4::printNumber() const
{
	cout << addNumber << endl;
}
void IPV4::num2address()
{
	int HEX = 0xff, shiftcnt = 0;

	for (int j = 0; j < 4; j++)
	{
		address[3 - j] = (addNumber & HEX) >> shiftcnt;

		shiftcnt += 8;
		HEX <<= 8;
	}
}
void IPV4::string2address(unsigned int *add)
{
	int shift = 24;

	for (int i = 0; i < 4; i++)
	{
		addNumber += add[i] << shift;
		shift -= 8;
	}
}