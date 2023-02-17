/*输入N个正整数，输出其中最小的能整除3的数。

输入
每行输入包含一组测试数据，包含N+1个整数，之间用空格分隔。 第1个整数代表N(1<=N<=100)，后面N个整数是需要统计的数据。

输出
如果存在满足条件的数，那么输出该数，如果没有则输出Null。*/

#include <stdio.h>

int main () {
	int a [ 100 ] = { 0 };
	char ch;
	int n = 0;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d" , &a [ i ] );
	}
	int temp = 0;
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( int i = 0 ; i < n ; i++ ) {
		if ( a [ i ] % 3 == 0 ) {
			printf ( "%d" , a [ i ] );
			return 0;
		}
	}
	printf ("Null");
	return 0;
}
