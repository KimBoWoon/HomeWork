/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                       모르스 부호                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char print(char *str);
void character(char *temp);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		char str[2001]={0};

		fscanf(file, "%s", str);

		character(str);
		puts("");
	}
}
void character(char *str)
{
	int i, j, n=0, len=strlen(str);
	char temp[5]={0};

	for(i=0;i<len+1;i++)
	{
		if(str[i]!='|' && str[i]!='#' && str[i]!='\0')
		{
			temp[n]=str[i];
			n++;
		}
		else
		{
			printf("%c", print(temp));
			n=0;
			for(j=0;j<5;j++)
				temp[j]=0;
		}
		if(str[i]=='#')
			printf("_");
	}
}
char print(char* temp)
{
	if(temp[0] == '.' && temp[1] == '-' && temp[2] == '\0') 
		return 'A';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '.' && temp[3] == '.' && temp[4] == '\0') 
		return 'B';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '-' && temp[3] == '.' && temp[4] =='\0') 
		return 'C';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '.' && temp[3] == '\0')
		return 'D';
	else if(temp[0] == '.' && temp[1] == '\0')
		return 'E';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '-' && temp[3] == '.' && temp[4] == '\0')
		return 'F';
	else if(temp[0] == '-' && temp[1] == '-' && temp[2] == '.' && temp[3] == '\0')
		return 'G';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '.' && temp[3] == '.' && temp[4] == '\0')
		return 'H';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '\0')
		return 'I';
	else if(temp[0] == '.' && temp[1] == '-' && temp[2] == '-' && temp[3] == '-' && temp[4] == '\0')
		return 'J';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '-' && temp[3] == '\0')
		return 'K';
	else if(temp[0] == '.' && temp[1] == '-' && temp[2] == '.' && temp[3] == '.' && temp[4] == '\0')
		return 'L';
	else if(temp[0] == '-' && temp[1] == '-' && temp[2] == '\0')
		return 'M';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '\0') 
		return 'N';
	else if(temp[0] == '-' && temp[1] == '-' && temp[2] == '-' && temp[3] == '\0')
		return 'O';
	else if(temp[0] == '.' && temp[1] == '-' && temp[2] == '-' && temp[3] == '.' && temp[4] == '\0')
		return 'P';
	else if(temp[0] == '-' && temp[1] == '-' && temp[2] == '.' && temp[3] == '-' && temp[4] == '\0')
		return 'Q';
	else if(temp[0] == '.' && temp[1] == '-' && temp[2] == '.' && temp[3] == '\0')
		return 'R';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '.' && temp[3] == '\0')
		return 'S';
	else if(temp[0] == '-' && temp[1] == '\0')
		return 'T';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '-' && temp[3] == '\0')
		return 'U';
	else if(temp[0] == '.' && temp[1] == '.' && temp[2] == '.' && temp[3] == '-' && temp[4] == '\0')
		return 'V';
	else if(temp[0] == '.' && temp[1] == '-' && temp[2] == '-' && temp[3] == '\0')
		return 'W';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '.' && temp[3] == '-' && temp[4] == '\0')
		return 'X';
	else if(temp[0] == '-' && temp[1] == '.' && temp[2] == '-' && temp[3] == '-' && temp[4] == '\0')
		return 'Y';
	else if(temp[0] == '-' && temp[1] == '-' && temp[2] == '.' && temp[3] == '.' && temp[4] == '\0')
		return 'Z';
} 