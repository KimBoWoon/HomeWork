/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                         정수 연산                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int big(int i, int j);	//큰 수를 찾아주는 함수
int equals(int r, int g);	//두 수가 같은지 판별하는 함수

void main(void)
{
	FILE *in_file;
	int i;
	int no_cases=0, start=0, end=0;
	int a=0, b=0;

	in_file = fopen("input.txt", "r");
	if(in_file == NULL)
		exit(1);
	
	fscanf(in_file, "%d", &no_cases);

	for(i=0;i<no_cases;i++)
	{
		fscanf(in_file, "%d %d", &a, &b);

		printf("%d %d %d %d %d %d %d %d\n", a+b, a-b, abs(a-b), a*b, a/b, a%b, big(a, b), equals(a, b));
	}
	fclose(in_file);
}

int big(int i, int j)	//큰 수를 찾아주는 함수
{
	if(i>j)	//i가 j보다 크면
		return i;	//i값을 반환
	else	//그렇지 않으면 j를 반환
		return j;
}

int equals(int r, int g)	//두 수가 같은지 판별하는 함수
{
	if(r==g)	//r과 g가 같으면
		return 1;	//1을 반환
	else	//같지 않으면 0를 반환
		return 0;
}