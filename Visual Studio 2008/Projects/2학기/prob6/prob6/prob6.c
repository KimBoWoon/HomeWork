/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*          �� ���� ������ ��� ������ �� ���ϱ�           *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int sum(int s, int t);	//�� ���� ������ ��� ������ ���� ������ �Լ�

void main(void)
{
	FILE *in_file;
	int i;
	int cases, start, end;

	in_file=fopen("input.txt","r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d %d", &start, &end);
		printf("%d\n", sum(start, end));	//�� ���� sum�̶�� �Լ��� ������.
	}

	fclose(in_file);
}

int sum(int s, int t)	//�� ���� ������ ��� ������ ���� ������ �Լ�
{
	int i, sum=0;

	for(i=s;i<=t;i++)
		sum+=i;	//s�� t���̿� �ִ� ��� �������� ���Ѵ�.

	return sum;
}