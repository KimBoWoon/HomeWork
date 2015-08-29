/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                     �Ӹ���� ����                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int reverse(int n);	//���Ѽ��ڸ� ������ �Լ�

int main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int value, value2;

		fscanf(file, "%d %d", &value, &value2);

		if((value+value2)==reverse(value+value2))
			printf("1\n");
		else
			printf("0\n");
	}
}
int reverse(int n)	//���Ѽ��ڸ� ������ �Լ�
{
	int j, k, count, mul, a, b, c, d;

	while(1)
	{
		count=d=0;
		a=n;
		c=mul=1;

		while(a>=10)	//�ڸ��� ���ϱ�
		{
			a/=10;
			count++;
		}
		for(j=0;j<count;j++)	//�ڸ�����ŭ 10���ϱ�
			mul*=10;
		for(k=0;k<=count;k++)	//��������� ���� ���ڸ� ������
		{
			b=n;
			b/=c;
			c*=10;
			b%=10;
			d+=b*mul;
			mul/=10;
		}
		return d;
	}
}