#include <iostream>
using namespace std;

typedef unsigned long ULONG;

ULONG Power(int Base, int Exponent);

int main()
{
	int Base;
	int Exponent;

	scanf_s("%d %d", &Base, &Exponent, sizeof(int), sizeof(int));

	printf("%d\n", Power(Base, Exponent));
}
ULONG Power(int Base, int Exponent)
{
	if (Exponent == 1)
		return Base;
	else if (Base == 0)
		return 1;

	if (Exponent % 2 == 0)
	{
		ULONG result = Power(Base, Exponent / 2);
		return result * result;
	}
	else
	{
		ULONG result = Power(Base, (Exponent - 1) / 2);
		return (result * result) * Base;
	}
}