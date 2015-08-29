#include <stdio.h>

int main(void)
{
	float a, b, d;
	int c;
	int e=0;

	while(1)
	{
		printf("¼ýÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
		scanf("%f %f", &a, &b);

		printf("µ¡¼À 1, »¬¼À 2, °ö¼À 3, ³ª´°¼À 4");
		scanf("%d", &c);

		switch(c)
		{
			case 1:
				d=a+b;
				printf("%f\n", d);
				break;
			case 2:
				d=a-b;
				printf("%f\n", d);
				break;
			case 3:
				d=a*b;
				printf("%f\n", d);
				break;
			case 4:
				d=a/b;
				printf("%f\n", d);
				break;
		}

		printf("Á¾·á 1, °è¼Ó 2");
		scanf("%d", &e);
		if(e==1)
			break;
		else
			continue;
	}

	return 0;
}