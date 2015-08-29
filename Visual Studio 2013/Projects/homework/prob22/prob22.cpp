/********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                 ���ڸ� 0�� ���� ���ϱ�                  *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file;
	int i, j, cases;

	file = fopen("input.txt", "r");
	if (file == NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for (i = 0; i < cases; i++)
	{
		int data, value, count1 = 0, count2 = 0, temp, count = 0;

		fscanf(file, "%d", &data);

		for (j = 0; j < data; j++)
		{
			fscanf(file, "%d", &value);

			temp = value;

			while (value % 2 == 0)	//2�� ��������
			{
				count1++;
				value /= 2;
			}
			while (temp % 5 == 0)	//5�� ��������
			{
				count2++;
				temp /= 5;
			}
			if (count1 >= count2)
			{
				count += count2;
				count1 = count1 - count2;
				count2 = 0;
			}
			else
			{
				count += count1;
				count2 = count2 - count1;
				count1 = 0;
			}
		}
		printf("%d\n", count);
	}
	fclose(file);
}