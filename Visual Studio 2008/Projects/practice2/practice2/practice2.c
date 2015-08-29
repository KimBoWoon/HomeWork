#include<stdio.h> 


int main( void )
{
	int x, y , count = 0, count2 = 1 ;
	//count 는 자기와 자기자신 나눠진 횟수, count2는 5번 출력인지 셀때
	for( x = 1 ; x <= 1000000000000000000 ; x++ )//1~100 이라면서 왜 2부터 시작하나요..
	{
		for( y = 1 ; y <= x ; y ++ )
		{
			if( ( x % y) == 0 )
			{
				count++ ;
			}
		}


		if( count == 2 ) // 소수는 1과 자기자신으로 나눴을때 0이므로.. 2개가 나옴.
		{
			count2 ++ ;
			printf( "%2d ", x ) ; // 자릿수 깔끔하게 보이기 위해서..
			if( count2 == 5 )
			{
				printf("\n");
				count2 = 0 ;
			}
		}
		else if( count == 1 )//1도 포함..
		{
			printf( "%2d ", x ) ;
		}


		count = 0 ;
	}


	return 0 ;
}
