/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*               매직 스퀘어 - 포인터 사용                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int **memory(int n);
void read(FILE *file, int **m, int n);
void compute(int **data, int n);

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
		int **data, value;

		fscanf(file, "%d", &value);

		data=memory(value);
		read(file, data, value);
		compute(data, value);
		free(*data);
		free(data);
	}
	fclose(file);
}
int **memory(int n)
{
	int i, **arr, *m;

	arr=(int **) malloc(sizeof(int *) * n);
	m=(int *) malloc(sizeof(int) * n * n);

	for(i=0;i<n;i++)
	{
		*(arr+i)=m;
		m+=n;
	}
	return arr;
}
void read(FILE *file, int **m, int n)
{
	int i, j, *arr;

	for(i=0;i<n;i++)
	{
		arr=*(m+i);
		for(j=0;j<n;j++)
			fscanf(file, "%d", arr++);
	}
}
void compute(int **data, int n)
{
	int i, j, sum=0, sum2=0, x=0, count=0;
	int *ptr;

	ptr=*data;
	for(i=0;i<n;i++)
		sum+=*ptr++;
	for(i=0;i<n;i++)
	{
		ptr=*(data+i);
		for(j=0;j<n;j++)
			sum2+=*ptr++;

		if(sum==sum2)
			count++;
		sum2=0;
	}
	for(i=0;i<n;i++)
	{
		ptr=*(data)+i;
		for(j=0;j<n;j++)
		{
			sum2+=*ptr;
			ptr+=n;
		}

		if(sum==sum2)
			count++;
		sum2=0;
	}
	ptr=*data;
	for(i=0;i<n;i++)
	{
		sum2+=*ptr++;
		ptr+=n;
	}
	if(sum==sum2)
		count++;
	sum2=0;
	ptr=*data+n-1;
	x=n-2;
	for(i=0;i<n;i++)
	{
		sum2+=*ptr++;
		ptr+=x;
	}
	if(sum==sum2)
		count++;
	sum2=0;

	if(count==(n*2+2))
		printf("%d\n", sum);
	else
		printf("-1\n");
}