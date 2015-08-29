#include "DEFINE.h"		//내가 만든 헤더파일 참조
#include "STRUCT.h"		//내가 만든 헤더파일 참조

void print(FILE *file, int count)	//출력해주는 함수
{
	int i, num, cnt = 0;
	float ave = 0;

	printf("===================================================\n");
	for (i = 0; i < count + 1; i++)
	{
		if (count == 1)	//count가 1이면 입력된 학생이 없다.
		{
			printf("입력된 학생이 없습니다.\n");
			break;
		}
		else if (stu[i].id == -1 && stu[i].score == -1)	//학번과 성적이 -1이면 비어있는곳이다.
			continue;
		else	//아니면 출력한다.
		{
			printf("%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
			cnt++;	//학생수를 나타내기위한 변수
			ave += stu[i].score;
		}
	}
	printf("평균 : %0.2f\n", ave / cnt);
	if (count != 1)	//count가 1일때는 학생수가 없으므로 출력하지 않는다.
		printf("현재까지 입력된 학생수는 %d명 입니다.\n", cnt);
	printf("===================================================\n");
	printf("이 결과를 파일에 출력하고 싶으시면 1을 아니면 다른숫자를 입력해주세요. ");
	num = getch();
	system("cls");	//화면을 지우는 함수
	if (num == 1)	//num이 1이면 파일에 출력한다.
	{
		fprint(file, i);	//파일에 출력하는 함수호출
		system("cls");
		printf("student.db 파일에 출력하고 프로그램을 종료합니다.\n");
		exit(0);	//프로그램 종료
	}
}