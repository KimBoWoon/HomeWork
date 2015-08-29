/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                  실습 시험 - 볼링 게임                  *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int *arr, int value);
void compute(int *arr, int value);

int main(void)
{
	FILE *file = fopen("input.txt", "r");
	int cases;

	if (file == NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while (cases--)
	{
		int value, arr[21] = { 0 }, sum = 0;

		fscanf(file, "%d", &value);

		read(file, arr, value);
		compute(arr, value);
	}
	fclose(file);
}
void read(FILE *file, int *arr, int value)
{
	int i;

	for (i = 0; i < value; i++)
		fscanf(file, "%d", &arr[i]);
}
void compute(int *arr, int value)
{
	int i, sum = 0, cnt = 0;

	for (i = 0; i < value;)
	{
		if (arr[i] + arr[i + 1] == 3)
		{
			sum += arr[i] + arr[i + 1] + arr[i + 2];
			i += 2;
			cnt++;
		}
		else if (arr[i] == 3)
		{
			sum += arr[i] + arr[i + 1] + arr[i + 2];
			i++;
			cnt++;
		}
		else if (arr[i] + arr[i + 1] < 3)
		{
			sum += arr[i] + arr[i + 1];
			i += 2;
			cnt++;
		}
		else if (arr[i] + arr[i + 1] > 3)
		{
			printf("error\n");
			break;
		}
		if (cnt == 10)
			i = value;
	}
	if (i == value)
		printf("%d\n", sum);
}