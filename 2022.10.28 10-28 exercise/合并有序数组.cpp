/*合并两个有序数组a,b。

输入
第一行输入两个数据m,n，分别代表数组a,b的长度，第二行第三行分别输入两个数组a,b,保证数组有序。

输出
将两个数组合并后输出，保证数组仍然有序。输出数据之间用空格隔开。*/

#include <stdio.h>

int main () {
	int na , nb , s;
	int nmin , nmax;
	int temp;
	int a [ 1000 ] = { 0 };
	int b [ 1000 ] = { 0 };
	int c [ 2000 ] = { 0 };
	scanf ( "%d%d" , &na , &nb );
	for ( int i = 0 ; i < na ; i++ ) {
		scanf ( "%d" , &a [ i ] );
	}
	for ( int i = 0 ; i < nb ; i++ ) {
		scanf ( "%d" , &b [ i ] );
	}//input array
	if ( na > nb ) {
		nmin = nb;
		nmax = na;
	} else {
		nmin = na;
		nmax = nb;
	}//most number of characters
	for ( int i = 0 ; i < nmin ; i++ ){
		c[ 2 * i ] = a [ i ];
		c[ 2 * i + 1 ] = b [ i ];
	}
	if ( na > nb ) {
		for ( int i = 0 ; i <= nmax - nmin ; i++ ) {
			c [ i + 2 * nmin ] = a [ i + nmin ];
		}
	} else {
		for ( int i = 0 ; i <= nmax - nmin ; i++ ) {
			c [ i + 2 * nmin ] = b [ i + nmin ];
		}
	}
	for ( int i = 0 ; i < na + nb ; i++ ) {
		for ( int j = 0 ; j < na + nb - i - 1 ; j++ ) {
			if ( c [ j + 1 ] < c [ j ] ) {
				temp = c [ j + 1 ];
				c [ j + 1 ] = c [ j ];
				c [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( int i = 0 ; i < na + nb ; i++ ) {
		printf ( "%d " , c [ i ] );
	}
	return 0;
}
