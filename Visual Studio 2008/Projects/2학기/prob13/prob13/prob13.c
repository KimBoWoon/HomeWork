/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                 ���ڷ� �簢�� ����ϱ�                  *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file;
	int i, cases;

	file=fopen("input.txt", "r");

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int width, height, h, j, value=1, temp;

		fscanf(file, "%d %d", &width, &height);

		temp=height;

		for(h=0;h<height;h++)
		{
			printf("%d ", value);

			for(j=0;j<width-1;j++)
			{
				printf("%d ", value+temp);
				temp+=height;
			}
			puts("");
			temp=height;
			value++;
		}
	}
	fclose(file);
}