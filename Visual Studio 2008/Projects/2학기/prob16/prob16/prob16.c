/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                        해밍 거리                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int hammingweight(unsigned int num);
int hammingdistance(unsigned int n1, unsigned int n2);
unsigned int xor(unsigned int x, unsigned int y);

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
		unsigned int num1, num2;

		fscanf(file, "%u %u", &num1, &num2);

		printf("%d %d %d\n", hammingweight(num1), hammingweight(num2), hammingweight(num1^num2));
	}
	fclose(file);
}
int hammingweight(unsigned int num)
{
	int weight=0;

	while(num)
	{
		if(num&0x01)
			weight++;
		num>>=1;
	}

	return weight;
}
int hammingdistance(unsigned int n1, unsigned int n2)
{
	int distance=0;

	while (n1 || n2)
	{
		if(xor(n1&0x01, n2&0x01))
			distance++;
		n1>>=1;
		n2>>=1;
	}

	return distance;
}
unsigned int xor(unsigned int x, unsigned int y)
{
	return !x^!y;
}