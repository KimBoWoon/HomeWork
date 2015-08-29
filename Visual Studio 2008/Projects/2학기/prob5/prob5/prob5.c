/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*					  ��Ȱ�� ��¥���                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void compute_easter(int y);	//��Ȱ�� ��¥�� ������� �Լ�

void main(void)
{
	FILE *in_file;
	int i;
	int no_cases;
	int year;

	in_file = fopen("input.txt", "r");
	if (in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &no_cases);

	for(i=0;i<no_cases;i++)
	{
		fscanf(in_file, "%d", &year);
		compute_easter(year);	//�⵵ ���� compute_easter�̶�� �Լ��� �����ش�.
	}
	fclose(in_file);
}

void compute_easter(int y)
{
	int c, n, t, i, j, k, l, p, q, o, u, w, r, b, v, x;
	int month, day;
	
	c = y/100;	//2�� �ܰ�
	n = y-(y/19)*19;	//3�� �ܰ�
	t = (c-17)/25;	//4�� �ܰ�
	o = c-(c/4)-(c-t)/3;	//5�� �ܰ�
	u = n*19+15;	//6�� �ܰ�
	i = o+u;	//7�� �ܰ�
	j = i-(i/30)*30;	//8�� �ܰ�
	w = j/28;	//9�� �ܰ�
	r = w-1;	//10�� �ܰ�
	b = 29/(j+1);	//11�� �ܰ�
	v = (21-n)/11;	//12�� �ܰ�
	k = j-(w*r*v*b);	//13�� �ܰ�
	x = y+(y/4)+j+2;	//14�� �ܰ�
	l = (x-c)+(c/4);	//15�� �ܰ�
	p = l-(l/7)*7;	//16�� �ܰ�
	q = k-p;	//17�� �ܰ�
	month = (q+40)/44+3;	//18�� �ܰ�
	day = (q+28)-(month/4)*31;	//19�� �ܰ�
	
	printf("%d %d\n", month, day);	//��Ȱ���� �ް� ���� ����Ѵ�.
}