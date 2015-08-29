/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*             텍스트 맞춤 - 가운데/양끝 맞춤              *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LEFTRIGHT(int w, char *str);
void MIDDLE(int w, char *str);

int main()
{
	FILE* file=fopen("input.txt", "r");
	int cases, i, data;
	char str[2001]={0};
	char temp[51]={0};

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		fscanf(file, "%d", &data);
		fscanf(file, "%s", str);

		for(i=strlen(str);;i+=strlen(temp))
		{
			fscanf(file,"%s",temp);
			if(temp[0]=='@') 
				break;
			str[i++]='_';
			str[i]='\0';
			strcat(str, temp);
		}
		MIDDLE(data, str);
		LEFTRIGHT(data, str);
	}
	fclose(file);
}
void MIDDLE(int w, char *str)
{
	int j, k=0, l=0, m;
	char temp[101]={0};

	for(j=0;j<strlen(str);j=k)
	{
		for(k=j, l=0;l<w && str[k]!='\0';k++, l++)
			temp[l]=str[k];
		if(str[k]!='_' && str[k]!='\0')
		{
			for(l=l-1;temp[l]!='_';l-- )
				k--;
		}
		else
			k++;

		temp[l]='\0';
		l=w-strlen(temp);
		if( l!=0 )
		{
			for( m=0; m<l/2; m++ )
				printf("_");
			printf("%s",temp);
			for( ; m<l; m++ )
				printf("_");
			puts("");
		}
		else
			printf("%s\n", temp);
	}
}
void LEFTRIGHT(int w, char *str)
{
	int i, j, k=0, l=0, m, n=0, o=0, cases;
	char temp[101]={0};

	for(j=0;j<strlen(str);j=k)
	{
		cases = 0;
		o=0;
		for(k=j, l=0;l<w && str[k]!='\0';k++, l++)
			temp[l]=str[k];

		if(str[k]=='\0')
		{
			temp[l]='\0'; 
			printf("%s\n", temp); 
			break;
		}
		if(str[k]!='_' && str[k]!='\0') 
		{		
			for(l=l-1;temp[l]!='_';l--)
				k--;
		}
		else
			k++;

		temp[l]='\0';

		for(i=0;temp[i]!='\0';i++)
		{
			if(temp[i]=='_') 
				cases++;
			else				 
				o++;
		}

		l = w-o;
		o=0;

		for(n=0;n<=cases;n++)
		{
			i = (cases-n != 0 )? l/(cases-n) : 0;
			for(;temp[o]!='_' && temp[o]!='\0';o++)
				printf("%c", temp[o]);
			o++;
			if(n==cases)
				break;
			for(m=0;m<i;m++, l--)
				printf("_");
		}
		puts("");
	}
}