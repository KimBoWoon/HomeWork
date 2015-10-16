#include <stdio.h>
#include <stdlib.h>

int checksum(unsigned int a);	//체크섬을 계산해줄 함수

#define MASK_LASTBIT 0xff;	//1바이트마다 계산해줄 마스크값

void main(void)
{
	FILE *file;
	int i, cases;

	file = fopen("input.txt", "r");
	if (file == NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for (i = 0; i < cases; i++)
	{
		unsigned int a;
		int temp;

		fscanf(file, "%d", &a);

		temp = a&MASK_LASTBIT;		//마지막 바이트의 체크섬 값

		if (checksum(a) == temp)	//체크섬==마지막 바이트의 값
			printf("1\n");
		else
			printf("0\n");
	}
	fclose(file);
}
int checksum(unsigned int a)	//체크섬을 계산해줄 함수
{
	int sum = 0, sum2 = 0;
	int b = 32;
	int temp;

	while (b != 0)
	{
		temp = a;
		b -= 8;	//1바이트씩 이동시켜줄 변수
		temp >>= b;	//1~4번째 바이트 구간을 찾아줌
		sum += temp&MASK_LASTBIT;	//각 바이트에있는 값을 모두 더 함

		if (sum >= 256)	//단계4
			sum -= 256;
		if (b == 0)	//4번째 바이트의 체크섬 계산
		{
			sum2 += temp&MASK_LASTBIT;	//sum2에 마지막 바이트 값을 넣어줌
			sum -= sum2;	//1~3번째 구간의 바이트 합-4번째 바이트의 합
		}
	}
	return 255 - sum;	//체크섬의 값
}