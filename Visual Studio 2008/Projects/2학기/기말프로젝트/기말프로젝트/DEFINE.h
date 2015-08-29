#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996)	//scanf와 fscanf의 경고문을 보지않기위해 선언

void MenuView();
int InputStudent(FILE *file, int count);	//학생정보를 관리하는 함수
void print(FILE *file, int count);	//학생정보를 출력하는 함수
void fprint(FILE *file, int count);	//학생정보를 파일에 출력하는 함수
void namesort(FILE *file, int count);	//학생정보를 이름순으로 소팅하는 함수
void studentidsort(FILE *file, int count);	//학생정보를 학번순으로 소팅하는 함수
void scoresort(FILE *file, int count);	//학생정보를 성적순으로 소팅하는 함수

/*내가 만든 헤더파일
여러 헤더파일과 여러 함수들을 참조하기위해 만든 헤더파일*/