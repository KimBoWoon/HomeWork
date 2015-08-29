#include <stdio.h>
#include <stdlib.h>

void compute_easter(int y);

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
		compute_easter(year);
	}
	fclose(in_file);
}

void compute_easter(int y)
{
	int c, n, t, i, j, k, l, p, q, o, u, w, r, b, v, x;
	int month, day;
	
	c = y/100; 
	n = y-(y/19)*19;
	t = (c-17)/25;
	o = c-(c/4)-(c-t)/3;
	u = n*19+15;
	i = o+u;
	j = i-(i/30)*30;
	w = j/28;
	r = w-1;
	b = 29/(j+1);
	v = (21-n)/11;
	k = j-(w*r*v*b);
	x = y+(y/4)+j+2;
	l = (x-c)+(c/4);
	p = l-(l/7)*7;
	q = k-p;
	month = (q+40)/44+3;
	day = (q+28)-(month/4)*31;
	
	printf("%d %d\n", month, day);
}