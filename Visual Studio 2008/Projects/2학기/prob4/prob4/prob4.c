/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                         ���� ����                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int big(int i, int j);	//ū ���� ã���ִ� �Լ�
int equals(int r, int g);	//�� ���� ������ �Ǻ��ϴ� �Լ�

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

int big(int i, int j)	//ū ���� ã���ִ� �Լ�
{
	if(i>j)	//i�� j���� ũ��
		return i;	//i���� ��ȯ
	else	//�׷��� ������ j�� ��ȯ
		return j;
}

int equals(int r, int g)	//�� ���� ������ �Ǻ��ϴ� �Լ�
{
	if(r==g)	//r�� g�� ������
		return 1;	//1�� ��ȯ
	else	//���� ������ 0�� ��ȯ
		return 0;
}