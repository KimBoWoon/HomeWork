#include <stdio.h>
#include <stdlib.h>

int combination(int n, int r);
int permutation(int n, int r);

int main(void)
{
	int n=12;
	int r=5;

	int recombination=0;
	int repermuation=0;

	if(n<=r)
	{
		printf("errer\n");
		exit(1);
	}

	recombination=combination(n, r);
	repermuation=permutation(n, r+1);

	printf("n = %d, r = %d\n", n, r);
	printf("1. Combination\n");
	printf("nCr = %d\n", recombination);
	printf("2. Permuation\n");
	printf("nPr = %d\n", repermuation);
}

int combination(int n, int r)
{
	return (n*permutation(n-1, r))/(r*permutation(r-1, r));
}
int permutation(int n, int r)
{
	static int cnt=1;

	if(cnt==r)
	{
		cnt=1;
		return 1;
	}
	else
	{
		cnt++;
		return n*permutation(n-1, r);
	}
}