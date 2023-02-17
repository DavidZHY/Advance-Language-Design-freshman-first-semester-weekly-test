/*中值滤波是对一个滑动窗口内的值进行排序，用其中值代替窗口中心点的原来值的滤波方法，它在抑制随机噪声的同时能有效保护原有信息。以一维信号的中值滤波举例。

对序列80 120 90 200 100 110 150，假设滤波窗口宽度为5,那么有

滤波窗口的子序列	子序列排序	待替换的值	序列中值
80 120 90 200 100	80 90 100 120 200	90	100
120 90 200 100 110	90 100 110 120 200	200	110
90 200 100 110 150	90 100 110 150 200	100	110
滤波窗口的值如果不够5个值那么不改变对应点的值， 比如左侧的80， 以它为中心的5个长度的窗口内没有5个数，所以这个点仍然是80不变。

所以最后滤波结果是80 120 100 110 110 110 150。

如果滤波窗口宽度为3，那么滤波结果是80 90 120 100 110 110 150。*/

#include <stdio.h>

#define LONG 10000

int main () {
	int a [ LONG ] = { 0 };
	int b [ LONG ] = { 0 };
	int c [ LONG ] = { 0 };
	int w , n;
	int i;
	int temp;
	while ( scanf ( "%d%d" , &w , &n ) != EOF ) {
		for ( i = 0 ; i < 100 ; i++ ) {
			a [ i ] = 0;
		}//initialize a[]
		for ( i = 0 ; i < n ; i++ ) {
			scanf ( "%d" , & a [ i ] );
			b [ i ] = a [ i ];
		}//input a[]
		if ( w % 2 == 0 ) {
			printf ("ERROR");
		} else {
			for ( i = 0 ; i < n - w + 1 ; i++ ) {
				for ( int j = 0 ; j < w ; j++ ) {
					c [ j ] = a [ j + i ];
				}
				for ( int k = 0 ; k < w ; k++ ) {
					for ( int j = 0 ; j < w - k - 1 ; j++ ) {
						if ( c [ j + 1 ] < c [ j ] ) {
							temp = c [ j + 1 ];
							c [ j + 1 ] = c [ j ];
							c [ j ] = temp;
							temp = 0;
						}
					}
				}//finish requeue c[]
				b [ w / 2 + i ] = c [ w / 2 ];
			}
			for ( int i = 0 ; i < n ; i++ ) {
				printf ( "%d " , b [ i ] );
			}
			printf ("\n");
		}
	}
	return 0;
}
