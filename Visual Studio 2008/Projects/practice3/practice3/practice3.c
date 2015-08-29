#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int a=10, b;

	srand(time(NULL));

	while(a--)
	{
		b=rand()%100;
		printf("%d ", b);
	}
}