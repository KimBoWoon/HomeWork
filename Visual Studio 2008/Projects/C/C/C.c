#include <stdio.h>

int main(void)
{
	int i, a, c;
	unsigned int b=1<<32-1;

	printf("숫자를 입력해 : ");
	scanf("%d", &a);

	printf("Bin");
	for(i=0;i<32;i++)
	{
		if(i%4==0)
			printf(" ");
		c=b>>i;
		printf("%d", (a&c)? 1:0);
	}
	puts("");
	printf("Oct %o Hex %x\n", a, a);
}