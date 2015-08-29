/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*              �����ʿ��� ���� ������ ����                *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void compute(int n);	//���Ѽ��ڸ� ������ �Լ�
int reverse(int value, int value2);	//���ڸ� ������ �Լ�

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

		compute(reverse(value, value2));
	}
	fclose(file);
}
int reverse(int value, int value2)
{
	int j, k, count, count2, mul, mul2, a, b, c, d, e, f;

	while(1)
	{
		count=count2=e=f=0;
		a=value;
		d=value2;
		c=mul=mul2=1;

		while(a>=10)	//�ڸ��� ���ϱ�
		{
			a/=10;
			count++;
		}
		while(d>=10)	//�ڸ��� ���ϱ�
		{
			d/=10;
			count2++;
		}
		for(j=0;j<count;j++)	//�ڸ�����ŭ 10���ϱ�
			mul*=10;
		for(j=0;j<count2;j++)	//�ڸ�����ŭ 10���ϱ�
			mul2*=10;
		for(k=0;k<=count;k++)	//���� ������
		{
			b=value;
			b/=c;
			c*=10;
			b%=10;
			e+=b*mul;
			mul/=10;
		}
		c=mul=mul2=1;
		for(j=0;j<count;j++)	//�ڸ�����ŭ 10���ϱ�
			mul*=10;
		for(j=0;j<count2;j++)	//�ڸ�����ŭ 10���ϱ�
			mul2*=10;
		for(k=0;k<=count2;k++)	//���� ������
		{
			b=value2;
			b/=c;
			c*=10;
			b%=10;
			f+=b*mul2;
			mul2/=10;
		}
		return e+f;	//������ ���� ���Ѱ� ��ȯ
	}
}
void compute(int n)	//���Ѽ��ڸ� ������ �Լ�
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
		printf("%d\n", d);
		break;
	}
}