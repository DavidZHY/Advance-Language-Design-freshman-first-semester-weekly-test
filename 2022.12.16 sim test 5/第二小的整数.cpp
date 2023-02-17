/*找出整数序列中第二小的数。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，第一个整数m，1≤m≤100，表示随后有m个整数。

输出
对每组数据，输出第二小的数。如果第二小的数不存在，则输出ERROR。*/

#include <stdio.h>

int main () {
	int l;
	int a [ 100 ];
	int n;
	int temp;
	int min;
	scanf ( "%d" , &l );
	for ( int k = 0 ; k < l ; k++ ) {
		scanf ( "%d" , &n );
		for ( int i = 0 ; i < n ; i++ ) {
			scanf ( "%d" , &a [ i ] );
		}//end entering array
		for ( int i = 0 ; i < n ; i++ ) {
			for ( int j = 0 ; j < n - i - 1 ; j++ ) {
				if ( a [ j ] > a [ j + 1 ] ) {
					temp = a [ j ];
					a [ j ] = a [ j + 1 ];
					a [ j + 1 ] = temp;
				}
			}
		}//end requeuing
		min = a [ 0 ];
		temp = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			if ( a [ i ] > min ) {
				printf ( "%d\n" , a [ i ] );
				temp++;
				break;
			}
		}
		if ( !temp ) {
			printf ("ERROR\n");
		}
	}
	return 0;
}
