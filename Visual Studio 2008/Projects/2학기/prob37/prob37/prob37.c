/**********************************************************
*              컴퓨터공학부 20113259 김보운               *
*                        성적 통계                        *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, int student, int *arr);
void max_min(int *arr, int student);
void average(int *arr, int student);
void middle(int *arr, int student);
void mode(int *arr, int student);

int main(void)
{
	FILE *file=fopen("input.txt", "r");
	int i, cases;

	if(file==NULL)
		exit(1);

	fscanf(file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		int student;
		int arr[100]={0};

		fscanf(file, "%d", &student);

		read(file, student, arr);
		max_min(arr, student);
		average(arr, student);
		middle(arr, student);
		mode(arr, student);
		puts("");
	}
}
void read(FILE *file, int student, int *arr)
{
	int i;

	for(i=0;i<student;i++)
		fscanf(file, "%d", &arr[i]);
}
void max_min(int *arr, int student)
{
	int i, max=arr[0], min=arr[0];

	for(i=0;i<student;i++)
	{
		if(max<arr[i])
			max=arr[i];
		if(min>arr[i])
			min=arr[i];
	}
	printf("%d %d ", max, min);
}
void average(int *arr, int student)
{
	int i;
	double n=0;

	for(i=0;i<student;i++)
		n+=arr[i];

	printf("%d ", (int)((n/student)+0.5));
}
void middle(int *arr, int student)
{
	int i, j, temp;
	double n, n2;

	for(i=0;i<=student-1;i++)
	{
		for(j=0;j<student-1;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	n=arr[student/2];
	n2=arr[(student/2)-1]+arr[student/2];
	if(student==1)
		printf("%d ", arr[0]);
	else if(student%2==0)
		printf("%d ", (int)((n2/2)+0.5));
	else
		printf("%d ", (int)n);
}
void mode(int *arr, int student)
{
	int i, j, temp, max=0, result, count=1;

	for(i=0;i<=student-1;i++)
	{
		for(j=0;j<student-1;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<student;i++)
	{
		if(arr[i]==arr[i+1])
			count++;
		else
		{
			if(max<count)
			{
				result=arr[i];
				max=count;
			}
			count=1;
		}
	}
	if(student==1)
		printf("%d", arr[0]);
	else
		printf("%d", result);
}