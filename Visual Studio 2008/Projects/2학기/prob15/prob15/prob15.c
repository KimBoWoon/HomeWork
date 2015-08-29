/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     바이트 스크램블                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

unsigned long bytescramble(unsigned long n, int a, int b, int c, int d);
unsigned long movebyte(unsigned long n, int from, int to);

void main(void)
{
	FILE *file;
	int cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		unsigned long value;
		int a, b, c, d;

		fscanf(file, "%lu %d %d %d %d", &value, &a, &b, &c, &d);

		printf("%u\n", bytescramble(value, a, b, c, d));
	}
	fclose(file);
}
unsigned long bytescramble(unsigned long n, int a, int b, int c, int d)
{
	unsigned long code=0;

	code|=movebyte(n, a, 4);
	code|=movebyte(n, b, 3);
	code|=movebyte(n, c, 2);
	code|=movebyte(n, d, 1);

	return code;
}
unsigned long movebyte(unsigned long n, int from, int to)
{
	unsigned long mask=0x00ff;
	unsigned long code=0;

	switch(from)
	{
	case 1:
		break;
	case 2:
		mask<<=8;
		break;
	case 3:
		mask<<=16;
		break;
	case 4:
		mask<<=24;
		break;
	}
	code=n&mask;

	if(to>from)
		code<<=(to-from)*8;
	else
		code>>=(from-to)*8;

	return code;
}