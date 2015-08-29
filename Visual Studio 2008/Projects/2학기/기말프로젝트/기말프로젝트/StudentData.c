#include "DEFINE.h"		//���� ���� ������� ����
#include "STRUCT.h"		//���� ���� ������� ����

void Manager(FILE *file, int count)
{
	char MenuNum;

	while (1)
	{
		MenuView();
		MenuNum = getch();
		puts("");

		switch (MenuNum)
		{
		case '1':
			InputStudent(file, count);
			break;
		case '2':
			ModifyStudent(file, count);
			break;
		case '3':
			DeleteStudent(file, count);
			break;
		case '4':
			PrintStudent(file, count);
			break;
		case '5':
			FilePrint(file, count);
			break;
		case '6':
			exit(1);
		default:
			printf("�߸��� �Է� �Դϴ�!\n");
			printf("�ٽ� �Է����ּ���\n");
		}
	}
}
int InputStudent(FILE* file, int count)	//�л����� �����ϴ� �Լ�
{
	int i, num;

	for (i = 0; i < 1000; i++)
	{
		if (stu[i].id == -1 && stu[i].score == -1)	//�й��� ������ -1�̸� ����ִ°��̴�.
		{
			//�л��Ѹ��� �Է� �޴´�.
			printf("�̸� : ");
			scanf("%s", stu[i].name);
			printf("�й� : ");
			scanf("%d", &stu[i].id);
			printf("���� : ");
			scanf("%f", &stu[i].score);
			count++;	//�л����� ��Ÿ���� ����

			printf("���� �Ͻ÷��� 1�� �Է��Ͻð� �ƴϸ� �ٸ����ڸ� �Է��ϼ���. ");
			num = getch();

			if (num == '1')	//num�� 1�̸� �л��߰� ����
			{
				system("cls");	//ȭ���� ����� �Լ�
				break;
			}
		}
		else	//�ƴϸ� �л������� ����ִ� ���̹Ƿ� continue�� �Ѵ�.
			continue;
	}
}
int ModifyStudent(FILE *file, int count)
{
	int i, StudentID, num;

	//�ϴ� � �л����� �Էµ��ִ��� ������ش�.
	printf("===========================================\n");
	for (i = 0; i < 1000; i++)
	{
		if (count == 1)	//count�� 1�̸� �Էµ� �л��� ����.
		{
			printf("�Էµ� �л��� �����ϴ�.\n");
			break;	//�Էµ� �л��� ������ ����Ż��
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//�й��� ������ -1�̸� ����ִ°��̴�.
			continue;
		else	//�ƴϸ� �л������� ����Ѵ�.
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
	printf("===========================================\n");
	if (count != 1)	//count�� 1�� �ƴϸ� �л����� �Ѹ��̻� �ִٴ� ���̴�.
	{
		printf("������ ���Ͻô� �л��� �й��� �Է����ּ���. ");
		scanf("%d", &StudentID);

		for (i = 0; i < 1000; i++)
		{
			if (stu[i].id == StudentID)		//�Էµ� �й��� ����� �й��� ������ �����Ѵ�.
			{
				printf("===========================================\n");
				printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);	//������ �л��� �� �л��� �´��� �ٽ� �ѹ� ����Ѵ�.
				printf("===========================================\n");
				printf("�����Ϸ��� �л��� �� �л��̸� 1�� �Է��Ͻð� �ƴϸ� �ٸ����ڸ� �Է����ּ���. ");
				num = getch();

				if (num == '1')	//num�� 1�̸� �����Ѵ�.
				{
					//������ �ϱ����� �ٽ� �Է¹޾Ƽ� ���� �����.
					printf("�̸� : ");
					scanf("%s", stu[i].name);
					printf("�й� : ");
					scanf("%d", &stu[i].id);
					printf("���� : ");
					scanf("%f", &stu[i].score);
					printf("���� �Ϸ�\n");
					break;	//������ �Ϸ�Ǹ� ����Ż��
				}
				else
					break;
			}
		}
	}
	if (i == 1000)	//i�� 100�̸� �л������� ������ �ȵȰ��̴�.
		printf("�������� �ʴ� �л��Դϴ�.\n");
	system("cls");
}
int DeleteStudent(FILE *file, int count)
{
	int i, StudentID, num;

	//�ϴ� � �л����� �Էµ��ִ��� ������ش�.
	printf("===========================================\n");
	for (i = 0; i < 1000; i++)
	{
		if (count == 1)	//count�� 1�̸� �Էµ� �л��� ����.
		{
			printf("�Էµ� �л��� �����ϴ�.\n");
			break;	//�Էµ� �л��� ������ ����Ż��
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//�й��� ������ -1�̸� ����ִ°��̴�.
			continue;
		else	//�ƴϸ� �л������� ����Ѵ�.
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
	printf("===========================================\n");
	if (count != 1)	//count�� 1�� �ƴϸ� �л����� �Ѹ��̻� �ִٴ� ���̴�.
	{
		printf("���Ÿ� �Ϸ��� �л��� �й��� �Է����ּ���. ");
		scanf("%d", &StudentID);

		for (i = 0; i < 1000; i++)
		{
			if (stu[i].id == StudentID)		//�Էµ� �й��� ����� �й��� ������ �����Ѵ�.
			{
				printf("===========================================\n");
				printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);	//������ �л��� �� �л��� �´��� �ٽ� �ѹ� ����Ѵ�.
				printf("===========================================\n");
				printf("�����Ϸ��� �л��� �� �л��̸� 1�� �Է��Ͻð� �ƴϸ� �ٸ����ڸ� �Է����ּ���. ");
				num = getch();

				if (num == '1')	//num�� 1�̸� �����Ѵ�.
				{
					//�����ϱ����� �й��� ������ ��� -1�� ä���.
					stu[i].id = -1;
					stu[i].score = -1;
					printf("���� �Ϸ�\n");
					count--;	//�л��� ���������Ƿ� �л���-1�� �����ش�.
					break;	//���Ű� �Ϸ�Ǹ� ����Ż��
				}
				else
					break;
			}
		}
	}
	if (i == 1000)	//i�� 100�̸� �л������� ������ �ȵȰ��̴�.
		printf("�������� �ʴ� �л��Դϴ�.\n");
}
int PrintStudent(FILE *file, int count)
{
	int PrintNum;

	printf("�̸������� ����� 1, �й������� ����� 2, ���������� ����� 3�� �Է����ּ���. ");
	PrintNum = getch();

	if (PrintNum == '1')	//num�� 1�̸� �̸��� ����
		namesort(file, count);	//�̸��� ������ �ϴ� �Լ���	ȣ��
	else if (PrintNum == '2')	//num�� 2�̸� �й��� ����
		studentidsort(file, count);	//�й��� ������ �ϴ� �Լ��� ȣ��
	else if (PrintNum == '3')	//num�� 3�̸� ������ ����
		scoresort(file, count);	//������ ������ �ϴ� �Լ��� ȣ��
}
int FilePrint(FILE *file, int count)
{
	system("cls");	//ȭ���� ����� �Լ�
	fprint(file, count);	//���Ͽ� ����ϴ� �Լ��� ȣ��
	printf("student.db ���Ͽ� ����ϰ� ���α׷��� �����մϴ�.\n");
	return 0;	//���α׷� ����
}