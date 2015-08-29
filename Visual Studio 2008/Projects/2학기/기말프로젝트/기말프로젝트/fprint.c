#include "DEFINE.h"		//내가 만든 헤더파일 참조
#include "STRUCT.h"		//내가 만든 헤더파일 참조

void fprint(FILE *file, int count)	//파일에 출력해주는 함수
{
	int i, cnt = 0;
	file = fopen("student.db", "w");	//파일을 쓰기용으로 연다.

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
			fprintf(file, "%s %d %0.2f\n", stu[i].name, stu[i].id, stu[i].score);
	}
}