#include "DEFINE.h"		//내가 만든 헤더파일 참조
#include "STRUCT.h"		//내가 만든 헤더파일 참조

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
			printf("잘못된 입력 입니다!\n");
			printf("다시 입력해주세요\n");
		}
	}
}
int InputStudent(FILE* file, int count)	//학생들을 관리하는 함수
{
	int i, num;

	for (i = 0; i < 1000; i++)
	{
		if (stu[i].id == -1 && stu[i].score == -1)	//학번과 성적이 -1이면 비어있는곳이다.
		{
			//학생한명을 입력 받는다.
			printf("이름 : ");
			scanf("%s", stu[i].name);
			printf("학번 : ");
			scanf("%d", &stu[i].id);
			printf("성적 : ");
			scanf("%f", &stu[i].score);
			count++;	//학생수를 나타내는 변수

			printf("종료 하시려면 1을 입력하시고 아니면 다른숫자를 입력하세요. ");
			num = getch();

			if (num == '1')	//num이 1이면 학생추가 종료
			{
				system("cls");	//화면을 지우는 함수
				break;
			}
		}
		else	//아니면 학생정보가 들어있는 곳이므로 continue를 한다.
			continue;
	}
}
int ModifyStudent(FILE *file, int count)
{
	int i, StudentID, num;

	//일단 어떤 학생들이 입력되있는지 출력해준다.
	printf("===========================================\n");
	for (i = 0; i < 1000; i++)
	{
		if (count == 1)	//count가 1이면 입력된 학생이 없다.
		{
			printf("입력된 학생이 없습니다.\n");
			break;	//입력된 학생이 없으면 루프탈출
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//학번과 성적이 -1이면 비어있는곳이다.
			continue;
		else	//아니면 학생정보를 출력한다.
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
	printf("===========================================\n");
	if (count != 1)	//count가 1이 아니면 학생수가 한명이상 있다는 것이다.
	{
		printf("변경을 원하시는 학생의 학번을 입력해주세요. ");
		scanf("%d", &StudentID);

		for (i = 0; i < 1000; i++)
		{
			if (stu[i].id == StudentID)		//입력된 학번과 저장된 학번이 같으면 변경한다.
			{
				printf("===========================================\n");
				printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);	//변경할 학생이 이 학생이 맞는지 다시 한번 출력한다.
				printf("===========================================\n");
				printf("변경하려는 학생이 이 학생이면 1을 입력하시고 아니면 다른숫자를 입력해주세요. ");
				num = getch();

				if (num == '1')	//num이 1이면 변경한다.
				{
					//변경을 하기위해 다시 입력받아서 덮어 씌운다.
					printf("이름 : ");
					scanf("%s", stu[i].name);
					printf("학번 : ");
					scanf("%d", &stu[i].id);
					printf("성적 : ");
					scanf("%f", &stu[i].score);
					printf("변경 완료\n");
					break;	//변경이 완료되면 루프탈출
				}
				else
					break;
			}
		}
	}
	if (i == 1000)	//i가 100이면 학생정보가 저장이 안된것이다.
		printf("존재하지 않는 학생입니다.\n");
	system("cls");
}
int DeleteStudent(FILE *file, int count)
{
	int i, StudentID, num;

	//일단 어떤 학생들이 입력되있는지 출력해준다.
	printf("===========================================\n");
	for (i = 0; i < 1000; i++)
	{
		if (count == 1)	//count가 1이면 입력된 학생이 없다.
		{
			printf("입력된 학생이 없습니다.\n");
			break;	//입력된 학생이 없으면 루프탈출
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//학번과 성적이 -1이면 비어있는곳이다.
			continue;
		else	//아니면 학생정보를 출력한다.
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
	printf("===========================================\n");
	if (count != 1)	//count가 1이 아니면 학생수가 한명이상 있다는 것이다.
	{
		printf("제거를 하려는 학생의 학번을 입력해주세요. ");
		scanf("%d", &StudentID);

		for (i = 0; i < 1000; i++)
		{
			if (stu[i].id == StudentID)		//입력된 학번과 저장된 학번이 같으면 제거한다.
			{
				printf("===========================================\n");
				printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);	//제거할 학생이 이 학생이 맞는지 다시 한번 출력한다.
				printf("===========================================\n");
				printf("제거하려는 학생이 이 학생이면 1을 입력하시고 아니면 다른숫자를 입력해주세요. ");
				num = getch();

				if (num == '1')	//num이 1이면 제거한다.
				{
					//제거하기위해 학번과 성적을 모두 -1로 채운다.
					stu[i].id = -1;
					stu[i].score = -1;
					printf("제거 완료\n");
					count--;	//학생을 제거했으므로 학생수-1를 시켜준다.
					break;	//제거가 완료되면 루프탈출
				}
				else
					break;
			}
		}
	}
	if (i == 1000)	//i가 100이면 학생정보가 저장이 안된것이다.
		printf("존재하지 않는 학생입니다.\n");
}
int PrintStudent(FILE *file, int count)
{
	int PrintNum;

	printf("이름순으로 출력은 1, 학번순으로 출력은 2, 성적순으로 출력은 3을 입력해주세요. ");
	PrintNum = getch();

	if (PrintNum == '1')	//num이 1이면 이름순 정렬
		namesort(file, count);	//이름순 정렬을 하는 함수를	호출
	else if (PrintNum == '2')	//num이 2이면 학번순 정렬
		studentidsort(file, count);	//학번순 정렬을 하는 함수를 호출
	else if (PrintNum == '3')	//num이 3이면 성적순 정렬
		scoresort(file, count);	//성적순 정렬을 하는 함수를 호출
}
int FilePrint(FILE *file, int count)
{
	system("cls");	//화면을 지우는 함수
	fprint(file, count);	//파일에 출력하는 함수를 호출
	printf("student.db 파일에 출력하고 프로그램을 종료합니다.\n");
	return 0;	//프로그램 종료
}