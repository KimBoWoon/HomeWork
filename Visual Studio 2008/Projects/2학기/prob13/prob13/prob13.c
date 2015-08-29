/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 숫자로 사각형 출력하기                  *
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