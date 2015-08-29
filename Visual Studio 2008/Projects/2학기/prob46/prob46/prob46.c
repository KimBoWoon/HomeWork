/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                  런(Run) - 포인터 사용                  *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int *memory(int cases2);
void read(FILE *file, int cases2, int *data);
void compute(int *data, int cases2);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int *data, cases2;

		fscanf(file, "%d", &cases2);

		data=memory(cases2);
		read(file, cases2, data);
		compute(data, cases2);
		free(data);
	}
	fclose(file);
}
int *memory(int cases2)
{
	int *arr;

	arr=(int*)malloc(sizeof(int) * cases2);

	return arr;
}
void read(FILE *file, int cases2, int *data)
{
	int i;

	for(i=0;i<cases2;i++)
		fscanf(file, "%d", data++);
}
void compute(int *data, int cases2)
{
	int j, count=1;

	if(cases2==1)
		printf("%d %d ", *data++, count);
	else
	{
		for(j=0;j<cases2-1;j++)
		{
			if(*(data+j)==*(data+(j+1)))
				count++;
			else
			{
				printf("%d %d ", *(data+j), count);
				count=1;
			}
			if(j==cases2-2)
				printf("%d %d ", *(data+(j+1)), count);
		}
	}
	puts("");
}