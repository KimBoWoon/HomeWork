#include <stdio.h>
#include <stdlib.h>

int icompare(const void *a, const void *b)
{
	return *(int *)a- *(int *)b;
}
void main()
{
	int i;
	int ints[]={6, 9, 5, 1, 3, 2, 4, 8, 7};

	qsort(ints, sizeof(ints)/sizeof(ints[0]), sizeof(int), icompare);

	for(i=0;i<sizeof(ints)/sizeof(ints[0]);i++)
		printf("%d ", ints[i]);
	puts("");
}