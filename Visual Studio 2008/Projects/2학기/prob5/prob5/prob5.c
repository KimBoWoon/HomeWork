/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*					  부활절 날짜계산                     *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void compute_easter(int y);	//부활절 날짜를 계산해줄 함수

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
		compute_easter(year);	//년도 값을 compute_easter이라는 함수에 보내준다.
	}
	fclose(in_file);
}

void compute_easter(int y)
{
	int c, n, t, i, j, k, l, p, q, o, u, w, r, b, v, x;
	int month, day;
	
	c = y/100;	//2번 단계
	n = y-(y/19)*19;	//3번 단계
	t = (c-17)/25;	//4번 단계
	o = c-(c/4)-(c-t)/3;	//5번 단계
	u = n*19+15;	//6번 단계
	i = o+u;	//7번 단계
	j = i-(i/30)*30;	//8번 단계
	w = j/28;	//9번 단계
	r = w-1;	//10번 단계
	b = 29/(j+1);	//11번 단계
	v = (21-n)/11;	//12번 단계
	k = j-(w*r*v*b);	//13번 단계
	x = y+(y/4)+j+2;	//14번 단계
	l = (x-c)+(c/4);	//15번 단계
	p = l-(l/7)*7;	//16번 단계
	q = k-p;	//17번 단계
	month = (q+40)/44+3;	//18번 단계
	day = (q+28)-(month/4)*31;	//19번 단계
	
	printf("%d %d\n", month, day);	//부활절의 달과 일을 출력한다.
}