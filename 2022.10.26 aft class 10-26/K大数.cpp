/*计算一个数组A[N]（N<=100）中，第K(1>=K && K <=N)小的数。

输入
第1行是一个整数N，表示数组A的大小，然后接收一个整数K（1>=K && K <=N）。最后读入N个整数，表示数组A的每一个元素。注意：数组元素是无序的，且任意两个元素不相等！！！

输出
输出数组A中第K小的元素*/

#include <stdio.h>

int main() {
	int a [ 100 ] = { 0 };
	int temp = 0;
    int n, i, k;
    scanf("%d%d", &n,&k);
    if ( k > n || k < 1 ) {
    	return 0;
    }
    for (i = 0; i < n ; i++) {
        scanf( "%d", &a [ i ] );
    }
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
	printf ( "%d" , a [ k - 1 ] );
    return 0;
}
