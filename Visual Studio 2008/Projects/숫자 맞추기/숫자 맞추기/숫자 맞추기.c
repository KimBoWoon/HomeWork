#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	int arr[]={4, 2, 1, 16, 32, 8};
	int temp=0, sum=0;

	printf("1~63까지 숫자를 하나 생각하세요!\n");
	printf("다음부터 보여질 숫자에 자기가 생각한 숫자가 있으면 1을 아니면 다른 숫자를 입력하세요.\n");
	printf("4 5 6 7 12 13 14 15 20 21 22 23 28 29 30 31 36 37 38 39 44 45 46 47 52 53 54 55 60 61 62 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[0];
	printf("2 3 6 7 10 11 14 15 18 19 22 23 26 27 30 31 34 35 38 39 42 43 46 47 50 51 54 55 58 59 62 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[1];
	printf("1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[2];
	printf("16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[3];
	printf("32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[4];
	printf("8 9 10 11 12 13 14 15 24 25 26 27 28 29 30 31 40 41 42 43 44 45 46 47 56 57 58 59 60 61 62 63\n");
	scanf("%d", &temp);
	if(temp==1)
		sum+=arr[5];

	printf("당신이 생각한 숫자는 [%d] 입니다.\n", sum);
	Sleep(3000);
}