/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
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
			if(value%divisor==0)	//value�� divisor�� �������� divisor�� value�� ����̴�.
			{
				sum+=divisor;	//������� ��
				num++;	//������� ����
			}
			else if(value/2==divisor)
				break;
		}
		printf("%d %d\n", num, sum);
	}
	fclose(file);
}