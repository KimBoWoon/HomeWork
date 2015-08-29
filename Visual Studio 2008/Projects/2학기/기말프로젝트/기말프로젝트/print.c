#include "DEFINE.h"		//���� ���� ������� ����
#include "STRUCT.h"		//���� ���� ������� ����

void print(FILE *file, int count)	//������ִ� �Լ�
{
	int i, num, cnt = 0;
	float ave = 0;

	printf("===================================================\n");
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
		{
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
			cnt++;	//�л����� ��Ÿ�������� ����
			ave += stu[i].score;
		}
	}
	printf("��� : %0.2f\n", ave / cnt);
	if (count != 1)	//count�� 1�϶��� �л����� �����Ƿ� ������� �ʴ´�.
		printf("������� �Էµ� �л����� %d�� �Դϴ�.\n", cnt);
	printf("===================================================\n");
	printf("�� ����� ���Ͽ� ����ϰ� �����ø� 1�� �ƴϸ� �ٸ����ڸ� �Է����ּ���. ");
	num = getch();
	system("cls");	//ȭ���� ����� �Լ�
	if (num == 1)	//num�� 1�̸� ���Ͽ� ����Ѵ�.
	{
		fprint(file, i);	//���Ͽ� ����ϴ� �Լ�ȣ��
		system("cls");
		printf("student.db ���Ͽ� ����ϰ� ���α׷��� �����մϴ�.\n");
		exit(0);	//���α׷� ����
	}
}