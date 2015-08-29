/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                  도트 프린터 출력하기                   *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dotpattern[][8][6] = {
	{{".XXX."}, {"X...X"}, {"X...X"}, {"X...X"}, {"X...X"}, {"X...X"}, {"X...X"}, {".XXX."}},
	{{"..X.."}, {".XX.."}, {"X.X.."}, {"..X.."}, {"..X.."}, {"..X.."}, {"..X.."}, {"XXXXX"}},
	{{".XXX."}, {"X...X"}, {"....X"}, {"...X."}, {"..X.."}, {".X..."}, {"X...."}, {"XXXXX"}},
	{{".XXX."}, {"X...X"}, {"....X"}, {"..XX."}, {"....X"}, {"....X"}, {"X...X"}, {".XXX."}},
	{{"...X."}, {"..XX."}, {".X.X."}, {"X..X."}, {"X..X."}, {"XXXXX"}, {"...X."}, {"...X."}},
	{{"XXXXX"}, {"X...."}, {"X...."}, {"XXXX."}, {"....X"}, {"....X"}, {"....X"}, {"XXXX."}},
	{{".XXX."}, {"X...X"}, {"X...."}, {"XXXX."}, {"X...X"}, {"X...X"}, {"X...X"}, {".XXX."}},
	{{"XXXXX"}, {"....X"}, {"....X"}, {"...X."}, {"..X.."}, {".X..."}, {".X..."}, {".X..."}},
	{{".XXX."}, {"X...X"}, {"X...X"}, {".XXX."}, {"X...X"}, {"X...X"}, {"X...X"}, {".XXX."}},
	{{".XXX."}, {"X...X"}, {"X...X"}, {".XXXX"}, {"....X"}, {"....X"}, {"X...X"}, {".XXX."}}
};

void print(int n);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while(cases--)
	{
		int val1, val2;

		fscanf(file, "%d %d", &val1, &val2);

		print(val1*val2);
	}
	fclose(file);
}
void print(int n)
{
	int i, temp=n, mul=1, count=1;

	for(i=0;i<8;i++)
	{
		temp=n;
		mul=1;
		count=1;
		while(temp>=10)
		{
			temp/=10;
			mul*=10;
			count++;
		}
		while(count--)
		{
			temp=n;

			temp/=mul;
			temp%=10;
			printf("%s", dotpattern[temp][i]);
			if(count>=1)
				printf(".");
			mul/=10;
		}
		puts("");
	}
}