#include <stdio.h>

int main(void)
{
	char num;

	for(num=33;num<127;num++)
		printf("%c %d %#o %#x\n", num, num, num, num);

	return 0;
}