#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class IPV4
{
public:
	IPV4();
	IPV4(unsigned int num);
	IPV4(unsigned int *add);

	void printAddress() const;
	void printNumber() const;

private:
	unsigned int addNumber;
	unsigned int address[4];

	void num2address();
	void string2address(unsigned int *add);
};