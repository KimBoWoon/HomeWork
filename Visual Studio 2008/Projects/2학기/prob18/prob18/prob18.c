/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                 회전시켜 모양이 같은 수                 *
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
		int j, a, value, value2, b, c, count2=0;

		fscanf(file, "%d %d", &value, &value2);

		for(;value<value2;value++)
		{
			int count=0, mul=1, mul2=10, data=0, data2=0;

			a=value;

			if(value<10 && (value==0 || value==1 || value==8))
				count2++;
			else
			{
				while(a>=10)
				{
					a/=10;
					count++;
					data2++;
				}
				if(count%2==0)
					count++;
				for(j=0;j<data2;j++)
					mul*=10;
				for(j=0;j<=count/2;j++)
				{
					b=value/mul;
					mul/=10;
					b%=10;
					c=value%mul2;
					if(mul2>=100)
						c/=mul2/10;
					mul2*=10;
					if(b==c || (b==6 && c==9) || (b==9 && c==6))
					{
						if((b==0 && c==0) || (b==1 && c==1) || (b==6 && c==9) || (b==8 && c==8) || (b==9 && c==6))
						{
							data++;
							continue;
						}
						if(data2==j && (b==0 || b==1 || b==8) && (c==0 || c==1 || c==8))
							count2++;
					}
					else
						break;
				}
				if(value>10 && data==(count/2)+1)
					count2++;
			}
		}
		printf("%d\n", count2);
	}
	fclose(file);
}