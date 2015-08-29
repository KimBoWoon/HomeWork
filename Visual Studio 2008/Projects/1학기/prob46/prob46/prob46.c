#include <stdio.h>
#include <stdlib.h>

unsigned int parity(unsigned int n);

void main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		unsigned int value;

		fscanf(file, "%u", &value);

		printf("%u\n", parity(value));
	}
	fclose(file);
}
unsigned int parity(unsigned int n)
{
	int i;
	unsigned int value, parity=0;

	value=n&0x7fffffffff;

	for(i=0;i<31;i++)
	{
		parity^=value&0x01;
		value>>=1;
	}
	if(parity)
		n|=0x80000000;

	return n;
}