#include <stdio.h>
#include <stdlib.h>

int checksum(unsigned int a);	//üũ���� ������� �Լ�

#define MASK_LASTBIT 0xff;	//1����Ʈ���� ������� ����ũ��

void main(void)
{
	FILE *file;
	int i, cases;

	file = fopen("input.txt", "r");
	if (file == NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for (i = 0; i < cases; i++)
	{
		unsigned int a;
		int temp;

		fscanf(file, "%d", &a);

		temp = a&MASK_LASTBIT;		//������ ����Ʈ�� üũ�� ��

		if (checksum(a) == temp)	//üũ��==������ ����Ʈ�� ��
			printf("1\n");
		else
			printf("0\n");
	}
	fclose(file);
}
int checksum(unsigned int a)	//üũ���� ������� �Լ�
{
	int sum = 0, sum2 = 0;
	int b = 32;
	int temp;

	while (b != 0)
	{
		temp = a;
		b -= 8;	//1����Ʈ�� �̵������� ����
		temp >>= b;	//1~4��° ����Ʈ ������ ã����
		sum += temp&MASK_LASTBIT;	//�� ����Ʈ���ִ� ���� ��� �� ��

		if (sum >= 256)	//�ܰ�4
			sum -= 256;
		if (b == 0)	//4��° ����Ʈ�� üũ�� ���
		{
			sum2 += temp&MASK_LASTBIT;	//sum2�� ������ ����Ʈ ���� �־���
			sum -= sum2;	//1~3��° ������ ����Ʈ ��-4��° ����Ʈ�� ��
		}
	}
	return 255 - sum;	//üũ���� ��
}