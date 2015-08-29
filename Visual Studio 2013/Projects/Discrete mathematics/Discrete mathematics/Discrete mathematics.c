#include <stdio.h>
#include <stdlib.h>

long factorialIterative(int n);
long factorialRecursive(int n);
long factorialDynamic(int n);

int fibonacciIterative(int n);
int fibonacciRecursive(int n);
int fibonacciDynamic(int n);

int powerIterative(int x, int y);
int powerRecursive(int x, int y);

int binarySearchIterative(const int data[], int size, int value);
int binarySearchRecursive(const int data[], int first, int last, int value);

void main()
{
	int fact = 10;
	int fibo = 10;
	int x = 2;
	int y = 11;
	int binarysearch[] = { 4, 7, 16, 20, 37, 38, 43 };
	int value = 37;
	int i, size;

	size = sizeof(binarysearch) / sizeof(int);

	printf("Factorial = %d\n", fact);
	printf("Factorial lIterative = %d\n", factorialIterative(fact));
	printf("Factorial lRecursive = %d\n", factorialRecursive(fact));
	printf("Factorial Dynamic = %d\n", factorialDynamic(fact));
	printf("Fibonacci = %d\n", fibo);
	printf("Fibonacci Iterative = ");
	fibonacciIterative(fibo - 2);
	printf("Fibonacci Recursive = ");
	fibonacciRecursive(fibo - 2);
	printf("\n");
	printf("Fibonacci Dynamic = ");
	fibonacciDynamic(fibo - 2);
	printf("x = %d, y = %d\n", x, y);
	printf("Power Iterative = %d\n", powerIterative(x, y));
	printf("Power Recursive = %d\n", powerRecursive(x, y));
	printf("Binary Search\n[ ");
	for (i = 0; i < size; i++)
		printf("%d ", binarysearch[i]);
	printf("] ");
	printf("\nvalue = %d\n", value);
	printf("Binary Search Iterative\n");
	binarySearchIterative(binarysearch, size, value);
	printf("Binary Search Recursive\n");
	binarySearchRecursive(binarysearch, 0, size, value);
}
long factorialIterative(int n)
{
	int i, fact = 1;

	for (i = 1; i <= n; i++)
		fact *= i;

	return fact;
}
long factorialRecursive(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorialRecursive(n - 1);
}
long factorialDynamic(int n)
{
	int i, fact[100] = { 0 };

	fact[0] = 1;

	for (i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i;

	return fact[n];
}

int fibonacciIterative(int n)
{
	int i, f1 = 0, f2 = 1, f3;

	printf("0 1 ");

	for (i = 0; i < n; i++)
	{
		f3 = f1 + f2;
		printf("%d ", f1 + f2);
		f1 = f2;
		f2 = f3;
	}
	printf("\n");

	return 1;
}
int fibonacciRecursive(int n)
{
	static int f1 = 0, f2 = 1, f3;

	if (f1 == 0 && f2 == 1)
		printf("0 1 1 ");
	else
		printf("%d ", f1 + f2);
	f3 = f1 + f2;
	f1 = f2;
	f2 = f3;

	if (n == 1)
		return 1;
	else
		return fibonacciRecursive(n - 1);
}
int fibonacciDynamic(int n)
{
	int i, f1, f2, f3, fibo[100] = { 0 };

	fibo[0] = f1 = 0, fibo[1] = f2 = 1, f3 = f1 + f2;

	for (i = 2; i <= n + 1; i++)
	{
		f3 = f1 + f2;
		fibo[i] = fibo[i - 2] + fibo[i - 1];
		f1 = f2;
		f2 = f3;
	}
	for (i = 0; i <= n + 1; i++)
		printf("%d ", fibo[i]);
	printf("\n");

	return 0;
}

int powerIterative(int x, int y)
{
	int i, power = 1;

	for (i = 0; i < y; i++)
		power *= x;

	return power;
}
int powerRecursive(int x, int y)
{
	static int cnt = 0;

	if (cnt == y)
		return 1;
	else
	{
		cnt++;
		return x*powerRecursive(x, y);
	}
}

int binarySearchIterative(const int data[], int size, int value)
{
	int i, min = 0, mid, max = size - 1;

	for (i = 0; min <= max; i++)
	{
		mid = (min + max) / 2;

		if (value == data[mid])
		{
			printf("Found in the %d index\n", mid, data[mid]);
			printf("binarysearch[%d] = %d\n", mid, data[mid]);
			return mid;
		}
		else if (value<data[mid])
			max = mid - 1;
		else
			min = mid + 1;
	}

	return -1;
}
int binarySearchRecursive(const int data[], int first, int last, int value)
{
	int mid = 0;
	static int i = 0;

	if (first>last)
		return -1;

	mid = (first + last) / 2;

	if (data[mid] == value)
	{
		printf("Found in the %d index\n", mid, data[mid]);
		printf("binarysearch[%d] = %d\n", mid, data[mid]);
		return mid;
	}
	else if (value < data[mid])
	{
		i++;
		return binarySearchRecursive(data, first, mid - 1, value);
	}
	else
	{
		i++;
		return binarySearchRecursive(data, mid + 1, last, value);
	}
}