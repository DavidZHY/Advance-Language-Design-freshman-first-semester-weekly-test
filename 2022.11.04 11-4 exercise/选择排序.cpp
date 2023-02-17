/*输入n个整数，使用选择排序算法按从小到大排序，然后输出结果。

输入
一行是1个整数n，表示随后有n个整数，第二行有n个整数，空格隔开。 

输出
输出结果有n-1行，每行为排序一趟后的结果。*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	int max = 0 , pos;
	int j;
	int a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%d" , &a [ k ] );
	}
	for ( int t = 0 ; t < n ; t++ ) {
		printf ( "%d " , a [ t ] );
	}
	printf ("\n");
	for ( int i = n - 1 ; i > 1 ; i-- ) {
		max = 0;
		for ( j = 0 ; j < i + 1 ; j++ ) {
			if ( a [ j ] > max ) {
				max = a [ j ];
				pos = j;
			}
		}
		if ( i != pos ) {
			temp = a [ i ];
			a [ i ] = a [ pos ];
			a [ pos ] = temp;
			temp = 0;
		}
		for ( int t = 0 ; t < n ; t++ ) {
			printf ( "%d " , a [ t ] );
		}
		printf ("\n");
	}
	return 0;
}
