/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 끝자리 숫자 계산하기(2)                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data;
	int a, b;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d", &data);

		b=1;

		for(j=0;j<data;j++)
		{
			fscanf(in_file, "%d", &a);

			b*=a%100;	//a를 100으로 나눠서 나온 나머지를 b에 곱한다
			b%=100;	//b를 계속 100으로 나눠주면서 두자리 숫자가 넘지 않게 한다(오버플로우 방지)
		}
		printf("%d\n", b);
	}
	fclose(in_file);
}
