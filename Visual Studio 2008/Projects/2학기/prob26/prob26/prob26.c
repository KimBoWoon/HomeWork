/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                오름차순으로 나열된 구간                 *
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
		int data[100]={0};
		int j, cases2, count=0, count2=0, count3=0;

		fscanf(file, "%d", &cases2);

		for(j=0;j<cases2;j++)
		{
			fscanf(file, "%d", &data[j]);
		}
		for(j=0;j<cases2-1;j++)
		{
			if(count3==0 && data[j]<=data[j+1])
			{
				count2+=data[j]+data[j+1];
				count++;
				count3++;
			}
			else if(data[j]<=data[j+1])
			{
				count2+=data[j+1];
				count3++;
			}
			else
				count3=0;
		}
		printf("%d %d\n", count, count2);
	}
	fclose(file);
}