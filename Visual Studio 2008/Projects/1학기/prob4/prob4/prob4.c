#include <stdio.h>
#include <stdlib.h>

int big(int i, int j);
int equals(int r, int g);

void main(void)
{
	FILE *in_file;
	int i;
	int no_cases=0, start=0, end=0;
	int a=0, b=0;

	in_file = fopen("input.txt", "r");
	if(in_file == NULL)
		exit(1);
	
	fscanf(in_file, "%d", &no_cases);


	for(i=0;i<no_cases;i++)
	{
		fscanf(in_file, "%d %d", &a, &b);

		printf("%d %d %d %d %d %d %d %d\n", a+b, a-b, abs(a-b), a*b, a/b, a%b, big(a, b), equals(a, b));
	}
	fclose(in_file);
}

int big(int i, int j)
{
	if(i>j)
		return i;
	else
		return j;
}

int equals(int r, int g)
{
	if(r==g)
		return 1;
	else
		return 0;
}