/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                         짧은 수                         *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int read(FILE *file);
void compute(int n);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
		compute(read(file));
}
int read(FILE *file)
{
	int n;

	fscanf(file, "%d", &n);

	return n;
}
void compute(int n)
{
	int i, temp=n, x=0, z=0, h=1, j=0;
	int arr[100]={n};

	while(1)
	{
		for(i=0;temp>=1;i++)
		{
			z=temp%10;
			x+=z*z;
			temp/=10;
		}
		arr[h]=x;
		h++;
		for(i=0;i<j;i++)
		{
			if(x==arr[i])
			{
				printf("%d %d %d\n", h-i-1, arr[i], i);
				return;
			}
		}
		j++;
		temp=x;
		if(x==1)
		{
			printf("0\n");
			break;
		}
		else
			x=0;
	}
}