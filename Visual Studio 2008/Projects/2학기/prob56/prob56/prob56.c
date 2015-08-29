/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                   Run Length Encoding                   *
**********************************************************/
#include <Stdio.h>
#include <stdlib.h>
#include <String.h>
#include <Math.h>

#define MAX 2001

void encoding(char *str);
void decoding(char *str);

int main(void)
{
	FILE *file=fopen("input.txt","r");

	int cases;

	if(file ==NULL)
		exit(1);
	
	fscanf(file, "%d", &cases);

	while(cases--)
	{
		int num;
		char str[MAX];

		fscanf(file, "%d %s", &num, str);

		if(num==0)
			encoding(str);
		else
			decoding(str);
	}
}
void encoding(char *str)
{
	int i, cnt=1, len=0, arr[MAX];
	int len2=strlen(str);
	char rle[MAX];

	printf("%d ",len2);

	for(i=1;i<=len2;i++)
	{
		if(str[i-1]==str[i])
			cnt++;
		else 
		{
			if(cnt<256)
			{
				arr[len]=cnt;
				rle[len]=str[i-1];
				len++;
			}
			else
			{
				while(cnt>255)
				{
					arr[len]=0;
					cnt-=256;
					rle[len]=str[i-1];
					len++;
				}
				if(cnt!=0)
				{
					arr[len]=cnt;
					rle[len]=str[i-1];
					len++;
				}
			}
			cnt=1;
		}
	}

	printf("%d ", len*2);

	for(i=0;i<len;i++)
		printf("%d%c", arr[i], rle[i]);

	printf("\n");
}
void decoding(char *str)
{
	int i, j, sum=0, mul=0, len=0, value=0, arr[MAX];
	int len2=strlen(str);
	char rle[MAX];

	for(i=0;i<len2;i++)
	{
		if(str[i]=='0' && (str[i-1]>'9' || i==0))
		{
			sum=256;
			mul=0;
		}
		else
		{
			if(str[i]<='9')
				mul++;
			else 
			{
				for(j=1;j<=mul;j++)
					sum+=(str[i-j]-48)*(int)pow(10,j-1);

				arr[len]=sum;
				rle[len]=str[i];
				len++;
				value+=sum;
				mul=0;
				sum=0;
			}
		}
	}

	printf("%d %d ", value, len*2);

	for(i=0;i<len;i++)
	{
		for(j=0;j<arr[i];j++)
			printf("%c", rle[i]);
	}
	printf("\n");
}