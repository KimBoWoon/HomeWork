/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int value, divisor, num=0, sum=0;

		fscanf(file, "%d", &value);

		for(divisor=1;divisor<value;divisor++)
		{
			if(value%divisor==0)	//value가 divisor로 나눠지면 divisor이 value의 약수이다.
			{
				sum+=divisor;	//진약수의 합
				num++;	//진약수의 개수
			}
			else if(value/2==divisor)
				break;
		}
		printf("%d %d\n", num, sum);
	}
	fclose(file);
}