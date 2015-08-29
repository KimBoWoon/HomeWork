/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 1차원 라이프(Life) 게임                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

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
		int data[50]={0}, temp[50]={0};
		int j, h, time, value;

		fscanf(file, "%d %d", &value, &time);

		for(j=0;j<value;j++)
		{
			fscanf(file, "%d", &data[j]);

			temp[j]=data[j];
		}
		for(j=0;j<time;j++)
		{
			for(h=0;h<value;h++)
			{
				if(h==0)
				{
					if(temp[h+1]<3)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h+1]>7)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h+1]>=4 && temp[h+1]<=7)
					{
						if(data[h]==9)
							continue;
						data[h]+=1;
					}
					else if(temp[h+1]==3)
						continue;
				}
				else if(h==value-1)
				{
					if(temp[h-1]<3)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h-1]>7)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h-1]>=4 && temp[h-1]<=7)
					{
						if(data[h]==9)
							continue;
						data[h]+=1;
					}
					else if(temp[h-1]==3)
						continue;
				}
				else
				{
					if(temp[h-1]+temp[h+1]<3)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h-1]+temp[h+1]>7)
					{
						if(data[h]==0)
							continue;
						data[h]-=1;
					}
					else if(temp[h-1]+temp[h+1]>=4 && temp[h-1]+temp[h+1]<=7)
					{
						if(data[h]==9)
							continue;
						data[h]+=1;
					}
					else if(temp[h-1]+temp[h+1]==3)
						continue;
				}
			}
			for(h=0;h<value;h++)
				temp[h]=data[h];
		}
		for(j=0;j<value;j++)
			printf("%d ", data[j]);
		puts("");
	}
	fclose(file);
}