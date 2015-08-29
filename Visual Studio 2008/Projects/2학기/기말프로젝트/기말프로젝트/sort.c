#include "DEFINE.h"		//���� ���� ������� ����
#include "STRUCT.h"		//���� ���� ������� ����

void swap(int i, int j)
{
	char str[20];	//�̸��� �ٲ��ֱ����� ���� ������ �迭
	float temp;	//������ �ٲٱ����� ���� �Ǽ��� ����
	long temp2;	//�й��� �ٲ��ֱ����� ���� ������ ����

	temp2 = stu[i].id;
	stu[i].id = stu[j].id;
	stu[j].id = temp2;
	temp = stu[i].score;
	stu[i].score = stu[j].score;
	stu[j].score = temp;
	strcpy(str, stu[i].name);
	strcpy(stu[i].name, stu[j].name);
	strcpy(stu[j].name, str);
}
void namesort(FILE *file, int count)	//�̸��� ����
{
	int i, j;	//�������� ���� �ϱ����� ���� ������ ����

	for (i = 0; i < count - 1; i++)	//�������� ���� �������
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name) > 0)
				swap(j, j + 1);
		}
	}
	print(file, count);	//������ִ� �Լ� ȣ��
}
void studentidsort(FILE *file, int count)	//�й��� ����
{
	int i, j;	//�������� ���� �ϱ����� ���� ������ ����

	for (i = 0; i < count - 1; i++)	//�������� ���� �������
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (stu[j].id > stu[j + 1].id)
				swap(j, j + 1);
		}
	}
	print(file, count);	//������ִ� �Լ� ȣ��
}
void scoresort(FILE *file, int count)	//������ ����
{
	int i, j;	//�������� ���� �ϱ����� ���� ������ ����

	for (i = 0; i < count - 1; i++)	//�������� ���� �������
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (stu[j].score > stu[j + 1].score)
				swap(j, j + 1);
		}
	}
	print(file, count);	//������ִ� �Լ� ȣ��
}