/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                     IPv4 주소변환                       *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef union
{
	struct
	{
		unsigned data1 : 8;
		unsigned data2 : 8;
		unsigned data3 : 8;
		unsigned data4 : 8;
	}IP;
	unsigned int data;
}ip;

int main(void)
{
	FILE *file = fopen("input.txt", "r");
	int cases;

	if (file == NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	while (cases--)
	{
		ip a;
		int num;
		char buf;

		fscanf(file, "%d", &num);

		if (num == 1)
		{
			unsigned int buf1, buf2, buf3, buf4;
			fscanf(file, "%u %c %u %c %u %c %u", &buf1, &buf, &buf2, &buf, &buf3, &buf, &buf4);

			a.IP.data4 = (unsigned char)buf1;
			a.IP.data3 = (unsigned char)buf2;
			a.IP.data2 = (unsigned char)buf3;
			a.IP.data1 = (unsigned char)buf4;

			printf("%u\n", a.data);
		}
		else
		{
			fscanf(file, "%d", &a.data);

			printf("%u.%u.%u.%u\n", (a.IP.data4), (a.IP.data3), (a.IP.data2), (a.IP.data1));
		}
	}
	fclose(file);
}