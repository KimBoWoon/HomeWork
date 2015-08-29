#include <stdio.h>
#include <stdlib.h>

#define MASK_LASTBIT 0x00000001

void main(void)
{
	FILE *file;
	int i;
	int num;

	file=fopen("input.txt", "r");
	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &num);
	
	for(i=0;i<num;i++)
	{
		unsigned int value;
		int bit0=0, bit1=0;

		fscanf(file, "%d", &value);

		while(value)
		{
			if(value & MASK_LASTBIT)
				bit1++;
			else
				bit0++;

			value >>=1;
		}
		printf("%d %d\n", bit0, bit1);
	}
	fclose(file);
}