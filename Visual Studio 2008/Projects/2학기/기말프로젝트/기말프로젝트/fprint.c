#include "DEFINE.h"		//���� ���� ������� ����
#include "STRUCT.h"		//���� ���� ������� ����

void fprint(FILE *file, int count)	//���Ͽ� ������ִ� �Լ�
{
	int i, cnt = 0;
	file = fopen("student.db", "w");	//������ ��������� ����.

	for (i = 0; i < count + 1; i++)
	{
		if (count == 1)	//count�� 1�̸� �Էµ� �л��� ����.
		{
			printf("�Էµ� �л��� �����ϴ�.\n");
			break;
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//�й��� ������ -1�̸� ����ִ°��̴�.
			continue;
		else	//�ƴϸ� ����Ѵ�.
			fprintf(file, "%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
}