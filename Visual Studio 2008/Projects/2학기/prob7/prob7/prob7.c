/**********************************************************
*              ��ǻ�Ͱ��к� 20113259 �躸��               *
*                 ���ڸ� ���� ����ϱ�(2)                 *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in_file;
	int i, j;
	int cases, data;
	int a, b;

	in_file=fopen("input.txt", "r");
	if(in_file==NULL)
		exit(1);

	fscanf(in_file, "%d", &cases);

	for(i=0;i<cases;i++)
	{
		fscanf(in_file, "%d", &data);

		b=1;

		for(j=0;j<data;j++)
		{
			fscanf(in_file, "%d", &a);

			b*=a%100;	//a�� 100���� ������ ���� �������� b�� ���Ѵ�
			b%=100;	//b�� ��� 100���� �����ָ鼭 ���ڸ� ���ڰ� ���� �ʰ� �Ѵ�(�����÷ο� ����)
		}
		printf("%d\n", b);
	}
	fclose(in_file);
}
