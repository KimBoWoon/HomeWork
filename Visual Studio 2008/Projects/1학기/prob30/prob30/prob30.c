#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *file;
	int test;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &test);

	while(test--)
	{
		int roll;
		int one, two, three, four, five, six;

		one=two=three=four=five=six=0;

		fscanf(file, "%d", &roll);

		while(roll--)
		{
			int num;

			fscanf(file, "%d", &num);

			switch(num)
			{
			case 1:
				one++;
				break;
			case 2:
				two++;
				break;
			case 3:
				three++;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			case 6:
				six++;
				break;
			}
		}
		printf("%d %d %d %d %d %d\n", one, two, three, four, five, six);
	}
	fclose(file);
}