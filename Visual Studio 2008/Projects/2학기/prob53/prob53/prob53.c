/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                    시이저 암호 기법                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file);
void compute(int value);
void print();

char str[100];

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

		fscanf(file, "%d", &value);

		read(file);
		compute(value);
		print();
	}
}
void read(FILE *file)
{
	fscanf(file, "%s", str);
}
void compute(int value)
{
	int i, num;

	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>64 && str[i]<91)
		{
			if(str[i]+value>90)
			{
				num=value-(90-str[i]);
				str[i]=65+num-1;
			}
			else
				str[i]+=value;
		}
		else if(str[i]>96 && str[i]<123)
		{
			if(str[i]+value>122)
			{
				num=value-(122-str[i]);
				str[i]=97+num-1;
			}
			else
				str[i]+=value;
		}
	}
}
void print()
{
	printf("%s\n", str);
}