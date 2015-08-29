/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     큰 팩토리얼 계산                    *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void factorial(int i);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int value;

		fscanf(file, "%d", &value);

		factorial(value);
	}
}
void factorial(int i)
{
	int h, count=1, a=0, j, g=1;
	int arr[1000]={1};

	for(j=1;j<i+1;j++)
	{
		a=0;
		count=0;
		for(h=0;h<1000;h++)
		{
			arr[h]*=j;
			arr[h]+=a;
			a=arr[h]/10000;
			arr[h]%=10000;
			count++;
		}
	}
	while(count--)
	{
		if(g==1 && arr[count]=='\0')
			continue;
		if(g!=1 && arr[count]<10)
			printf("000");
		else if(g!=1 && arr[count]<100)
			printf("00");
		else if(g!=1 && arr[count]<1000)
			printf("0");

		printf("%d", arr[count]);
		g++;
	}
	puts("");
}