#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int salary[100] = { 0 };
	int i;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
		salary[i] = rand() % 801 + 200;

	for (i = 0; i < 100; i++)
		printf("%d ", salary[i]);
}