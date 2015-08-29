/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                      날짜/시간 분석                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef union
{
	struct
	{
		unsigned date		:3;
		unsigned day		:5;
		unsigned month		:4;
		unsigned year		:8;
		unsigned reserved	:12;
	}datefield;
	unsigned int date;
}datepart;

typedef union
{
	struct
	{
		unsigned thousand	:10;
		unsigned second		:6;
		unsigned minute		:6;
		unsigned hour		:5;
		unsigned reserved	:5;
	}timefield;
	unsigned int time;
}timepart;

void print(datepart d, timepart t);

void main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		datepart d;
		timepart t;

		fscanf(file, "%u %u", &d.date, &t.time);
		print(d, t);
	}
	fclose(file);
}
void print(datepart d, timepart t)
{
	char *arr[]={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	printf("%u/%02u/%02u %s %02u:%02u:%02u %03u\n", d.datefield.year+1980, d.datefield.month, d.datefield.day, arr[d.datefield.date-1], t.timefield.hour, t.timefield.minute, t.timefield.second, t.timefield.thousand);
}