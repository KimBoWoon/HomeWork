#include<stdio.h> 


int main( void )
{
	int x, y , count = 0, count2 = 1 ;
	//count �� �ڱ�� �ڱ��ڽ� ������ Ƚ��, count2�� 5�� ������� ����
	for( x = 1 ; x <= 1000000000000000000 ; x++ )//1~100 �̶�鼭 �� 2���� �����ϳ���..
	{
		for( y = 1 ; y <= x ; y ++ )
		{
			if( ( x % y) == 0 )
			{
				count++ ;
			}
		}


		if( count == 2 ) // �Ҽ��� 1�� �ڱ��ڽ����� �������� 0�̹Ƿ�.. 2���� ����.
		{
			count2 ++ ;
			printf( "%2d ", x ) ; // �ڸ��� ����ϰ� ���̱� ���ؼ�..
			if( count2 == 5 )
			{
				printf("\n");
				count2 = 0 ;
			}
		}
		else if( count == 1 )//1�� ����..
		{
			printf( "%2d ", x ) ;
		}


		count = 0 ;
	}


	return 0 ;
}
