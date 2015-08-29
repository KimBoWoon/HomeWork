/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*          두 정수 사이의 모든 정수의 합 구하기           *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int sum(int s, int t);	//두 정수 사이의 모든 정수의 합을 구해줄 함수

void main(void)
{
	FILE *in_file;
	int i;
	int cases, start, end;

	in_file=fopen("input.txt","r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d %d", &start, &end);
		printf("%d\n", sum(start, end));	//두 수를 sum이라는 함수에 보낸다.
	}

	fclose(in_file);
}

int sum(int s, int t)	//두 정수 사이의 모든 정수의 합을 구해줄 함수
{
	int i, sum=0;

	for(i=s;i<=t;i++)
		sum+=i;	//s와 t사이에 있는 모든 정수들을 더한다.

	return sum;
}