#include <stdio.h>

int main(void)
{
	float a, b, d;
	int c;
	int e=0;

	while(1)
	{
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%f %f", &a, &b);

		printf("���� 1, ���� 2, ���� 3, ������ 4");
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

		printf("���� 1, ��� 2");
		scanf("%d", &e);
		if(e==1)
			break;
		else
			continue;
	}

	return 0;
}