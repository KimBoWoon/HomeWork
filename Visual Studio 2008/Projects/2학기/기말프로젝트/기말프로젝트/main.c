#include "DEFINE.h"		//���� ���� ������� ����
#include "STRUCT.h"		//���� ���� ������� ����

int main(void)	//main�Լ�
{
	FILE *file = fopen("student.db", "a+");	//������ a+���� ����.
	int i, count = 0;
	
	for (i = 0; i < 1000; i++)	//����ü�迭�� -1�� �����Ѵ�.
	{
		stu[i].id = -1;
		stu[i].score = -1;
	}
	for (i = 0; !feof(file); i++)	//���Ͽ� ����� ���� ������ �о�鿩�´�.
	{
		fscanf(file, "%s %d %f", stu[i].name, &stu[i].id, &stu[i].score);
		count++;	//�л����� ��Ÿ�������� ����
	}

	Manager(file, count);

	fclose(file);	//������ �ݴ´�.
}