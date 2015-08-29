/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                        정수 표현                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec(char *str);
void oct(char *str);
void hex(char *str);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		char str[257]={0};

		fscanf(file, "%s", str);

		if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
			hex(str);
		else if(str[0]=='0')
			oct(str);
		else if(str[0]>='0' && str[0]<='9')
			dec(str);
		else
			printf("0\n");
	}
}
void dec(char *str)
{
	int i, len=strlen(str);

	for(i=0;i<len;i++)
	{
		if(str[i]>='0' && str[i]<='9')
			continue;
		else
		{
			printf("0\n");
			return;
		}
	}
	printf("10\n");
}
void oct(char *str)
{
	int i, len=strlen(str);
	
	for(i=1;i<len;i++)
	{
		if(str[i]>='0' && str[i]<='7')
			continue;
		else
		{
			printf("0\n");
			return;
		}
	}
	printf("8\n");
}
void hex(char *str)
{
	int i, len=strlen(str);

	if(len==2)
	{
		printf("0\n");
		return;
	}
	for(i=2;i<len;i++)
	{
		if((str[i]>='A' && str[i]<='F') || (str[i]>='a' && str[i]<='f'))
			continue;
		else if(str[i]>='0' && str[i]<='9')
			continue;
		else
		{
			printf("0\n");
			return;
		}
	}
	printf("16\n");
}