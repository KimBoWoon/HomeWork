#include "DEFINE.h"		//내가 만든 헤더파일 참조
#include "STRUCT.h"		//내가 만든 헤더파일 참조

int main(void)	//main함수
{
	FILE *file = fopen("student.db", "a+");	//파일을 a+모드로 연다.
	int i, count = 0;
	
	for (i = 0; i < 1000; i++)	//구조체배열에 -1을 저장한다.
	{
		stu[i].id = -1;
		stu[i].score = -1;
	}
	for (i = 0; !feof(file); i++)	//파일에 저장된 값이 있으면 읽어들여온다.
	{
		fscanf(file, "%s %d %f", stu[i].name, &stu[i].id, &stu[i].score);
		count++;	//학생수를 나타내기위한 변수
	}

	Manager(file, count);

	fclose(file);	//파일을 닫는다.
}