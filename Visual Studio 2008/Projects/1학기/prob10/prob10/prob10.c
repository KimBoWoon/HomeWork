#include <stdio.h>

int main()
{
    FILE *in_file;
    int i, j;
    int cases, data;
    int a, b, c;
    int x, y, z, k, l;

    in_file = fopen("input.txt", "r");
    if(in_file==NULL)
		exit(1);

    fscanf(in_file, "%d", &cases);
    for(i=0;i<cases;i++)
    {
        x=y=z=k=l=0;

        fscanf(in_file, "%d", &data);
        fscanf(in_file, "%d", &a);
        fscanf(in_file, "%d", &b);
       
		for(j=2;j<data;j++)
        {
            fscanf(in_file, "%d", &c);
            if(a<=b && b<=c) 
				x++;
            if(a>=b && b>=c) 
				y++;
            if(a==b && b==c) 
				z++;
            if((a==b && b!=c) || (a==c && b!=c) || (b==c && a!=b)) 
				k++;
            if(a!=b && b!=c && a!=c) 
				l++;
            a = b;
            b = c;
        }
        printf("%d %d %d %d %d\n", x, y, z, k, l);

    }

    fclose(in_file);
}