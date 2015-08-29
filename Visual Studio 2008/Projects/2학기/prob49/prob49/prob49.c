/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*         1차원 라이프(Life) 게임 - 포인터 사용           *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int *memory(int size);
void read(FILE *file, int *data, int *temp, int size);
void game(int *data, int *temp, int time, int value);

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
		int *data, *temp;
		int time, value;

		fscanf(file, "%d %d", &value, &time);

		data=memory(value);
		temp=memory(value);
		read(file, data, temp, value);
		game(data, temp, time, value);
	}
	fclose(file);
}
int *memory(int size)
{
	int *arr;

	arr=(int *)malloc(sizeof(int) * size);

	return arr;
}
void read(FILE *file, int *data, int *temp, int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		fscanf(file, "%d", data+i);

		*(temp+i)=*(data+i);
	}
}
void game(int *data, int *temp, int time, int value)
{
	int j, h;

	for(j=0;j<time;j++)
	{
		for(h=0;h<value;h++)
		{
			if(h==0)
			{
				if(*(temp+(h+1))<3)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h+1))>7)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h+1))>=4 && *(temp+(h+1))<=7)
				{
					if(*(data+h)==9)
						continue;
					*(data+h)+=1;
				}
				else if(*(temp+(h+1))==3)
					continue;
			}
			else if(h==value-1)
			{
				if(*(temp+(h-1))<3)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h-1))>7)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h-1))>=4 && *(temp+(h-1))<=7)
				{
					if(*(data+h)==9)
						continue;
					*(data+h)+=1;
				}
				else if(*(temp+(h-1))==3)
					continue;
			}
			else
			{
				if(*(temp+(h-1))+*(temp+(h+1))<3)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h-1))+*(temp+(h+1))>7)
				{
					if(*(data+h)==0)
						continue;
					*(data+h)-=1;
				}
				else if(*(temp+(h-1))+*(temp+(h+1))>=4 && *(temp+(h-1))+*(temp+(h+1))<=7)
				{
					if(*(data+h)==9)
						continue;
					*(data+h)+=1;
				}
				else if(*(temp+(h-1))+*(temp+(h+1))==3)
					continue;
			}
		}
		for(h=0;h<value;h++)
			*(temp+h)=*(data+h);
	}
	for(j=0;j<value;j++)
		printf("%d ", *(data+j));
	puts("");
}