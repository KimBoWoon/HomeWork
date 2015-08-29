#include <stdio.h>
#include <stdlib.h>

int length(int n);

void main(void)
{
	FILE *file;
	int test;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &test);

	while(test--)
	{
		int n;

		fscanf(file, "%d", &n);

		printf("%d\n", length(n));
	}
	fclose(file);
}

int length(int n)
{
	int len=1;

	while(n!=1)
	{
		if(n%4==0)
			n=n/4;
		else if(n%2==0)
			n=n/2;
		else if(n%2==1)
			n=n*3+1;
		len++;
	}
	return len;
}