/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                       축구팀 순위                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct team
{
	char name[32];
	int win, draw, loss;
	int point;
}arr[MAX];

int size;

void read(FILE *file);
void compareteam(int size);
void print(int size);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		read(file);
		compareteam(size);
		print(size);
	}
}
void read(FILE *file)
{
	int i;

	fscanf(file, "%d", &size);

	for(i=0;i<size;i++)
	{
		fscanf(file, "%s %d %d %d", arr[i].name, &arr[i].win, &arr[i].draw, &arr[i].loss);

		arr[i].point=(arr[i].win*2)+arr[i].draw;
	}
}
void compareteam(int size)
{
	int i, j, temp;
	char str1[32];

	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j].point < arr[j+1].point)
			{
				temp = arr[j].point;
				arr[j].point = arr[j+1].point;
				arr[j+1].point = temp;
				temp = arr[j].win;
				arr[j].win = arr[j+1].win;
				arr[j+1].win = temp;
				temp = arr[j].draw;
				arr[j].draw = arr[j+1].draw;
				arr[j+1].draw = temp;
				temp = arr[j].loss;
				arr[j].loss = arr[j+1].loss;
				arr[j+1].loss = temp;
				strcpy(str1, arr[j].name);
				strcpy(arr[j].name, arr[j+1].name);
				strcpy(arr[j+1].name, str1);
			}
			else if(arr[j].point == arr[j+1].point)
			{
				if(arr[j].win < arr[j+1].win)
				{
					temp = arr[j].point;
					arr[j].point = arr[j+1].point;
					arr[j+1].point = temp;
					temp = arr[j].win;
					arr[j].win = arr[j+1].win;
					arr[j+1].win = temp;
					temp = arr[j].draw;
					arr[j].draw = arr[j+1].draw;
					arr[j+1].draw = temp;
					temp = arr[j].loss;
					arr[j].loss = arr[j+1].loss;
					arr[j+1].loss = temp;
					strcpy(str1, arr[j].name);
					strcpy(arr[j].name, arr[j+1].name);
					strcpy(arr[j+1].name, str1);
				}
				else if(arr[j].win == arr[j+1].win)
				{
					if(arr[j].draw < arr[j+1].draw)
					{
						temp = arr[j].point;
						arr[j].point = arr[j+1].point;
						arr[j+1].point = temp;
						temp = arr[j].win;
						arr[j].win = arr[j+1].win;
						arr[j+1].win = temp;
						temp = arr[j].draw;
						arr[j].draw = arr[j+1].draw;
						arr[j+1].draw = temp;
						temp = arr[j].loss;
						arr[j].loss = arr[j+1].loss;
						arr[j+1].loss = temp;
						strcpy(str1, arr[j].name);
						strcpy(arr[j].name, arr[j+1].name);
						strcpy(arr[j+1].name, str1);
					}
					else if(arr[j].draw == arr[j+1].draw)
					{
						if(arr[j].loss > arr[j+1].loss)
						{
							temp = arr[j].point;
							arr[j].point = arr[j+1].point;
							arr[j+1].point = temp;
							temp = arr[j].win;
							arr[j].win = arr[j+1].win;
							arr[j+1].win = temp;
							temp = arr[j].draw;
							arr[j].draw = arr[j+1].draw;
							arr[j+1].draw = temp;
							temp = arr[j].loss;
							arr[j].loss = arr[j+1].loss;
							arr[j+1].loss = temp;
							strcpy(str1, arr[j].name);
							strcpy(arr[j].name, arr[j+1].name);
							strcpy(arr[j+1].name, str1);
						}
						else if(arr[j].loss == arr[j+1].loss)
						{
							if(strcmp(arr[j].name, arr[j+1].name)>0)
							{
								temp = arr[j].point;
								arr[j].point = arr[j+1].point;
								arr[j+1].point = temp;
								temp = arr[j].win;
								arr[j].win = arr[j+1].win;
								arr[j+1].win = temp;
								temp = arr[j].draw;
								arr[j].draw = arr[j+1].draw;
								arr[j+1].draw = temp;
								temp = arr[j].loss;
								arr[j].loss = arr[j+1].loss;
								arr[j+1].loss = temp;
								strcpy(str1, arr[j].name);
								strcpy(arr[j].name, arr[j+1].name);
								strcpy(arr[j+1].name, str1);
							}
						}
					}
				}
			}
		}
	}
}
void print(int size)
{
	int i;

	for(i=0;i<size;i++)
		printf("%s %d\n", arr[i].name, arr[i].point);
}