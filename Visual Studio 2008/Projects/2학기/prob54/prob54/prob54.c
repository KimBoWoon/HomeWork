/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                    숫자의 진법 변환(3)                  *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		int value;

		fscanf(file, "%x", &value);

		printf("%d\n", value);
	}
	fclose(file);
}