#include "DEFINE.h"		//내가 만든 헤더파일 참조
#include "STRUCT.h"		//내가 만든 헤더파일 참조

void swap(int i, int j)
{
	char str[20];	//이름을 바꿔주기위해 만든 문자형 배열
	float temp;	//점수를 바꾸기위해 만든 실수형 변수
	long temp2;	//학번을 바꿔주기위해 만든 정수형 변수

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
void namesort(FILE *file, int count)	//이름순 소팅
{
	int i, j;	//오름차순 정렬 하기위해 만든 정수형 변수

	for (i = 0; i < count - 1; i++)	//오름차순 정렬 버블소팅
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name) > 0)
				swap(j, j + 1);
		}
	}
	print(file, count);	//출력해주는 함수 호출
}
void studentidsort(FILE *file, int count)	//학번순 소팅
{
	int i, j;	//오름차순 정렬 하기위해 만든 정수형 변수

	for (i = 0; i < count - 1; i++)	//오름차순 정렬 버블소팅
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (stu[j].id > stu[j + 1].id)
				swap(j, j + 1);
		}
	}
	print(file, count);	//출력해주는 함수 호출
}
void scoresort(FILE *file, int count)	//성적순 소팅
{
	int i, j;	//오름차순 정렬 하기위해 만든 정수형 변수

	for (i = 0; i < count - 1; i++)	//오름차순 정렬 버블소팅
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (stu[j].score > stu[j + 1].score)
				swap(j, j + 1);
		}
	}
	print(file, count);	//출력해주는 함수 호출
}