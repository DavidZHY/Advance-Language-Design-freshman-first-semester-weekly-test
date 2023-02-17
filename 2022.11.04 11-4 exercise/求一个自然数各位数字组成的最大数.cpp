/*求一个自然数各位数字组成的最大数。

输入
第1行是一个整数N，表示随后有N组数据。
每组数据包含1个 自然数num。

输出
对每组数据，输出num各位数字组成的最大数，并换行。*/

#include <stdio.h>

int main () {
	int n , digit = 0;
	int temp = 0;
	int a [ 100 ] = { 0 };
	char ch;
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		digit = 0;
		temp = 0;
		ch = getchar ();
		while ( ch != '\n' ) {
			a [ digit ] = ch - 48;
			digit++;
			ch = getchar ();
		}
		for ( int i = 0 ; i < digit ; i++ ) {
			for ( int j = 0 ; j < digit - i - 1 ; j++ ) {
				if ( a [ j + 1 ] > a [ j ] ) {
					temp = a [ j + 1 ];
					a [ j + 1 ] = a [ j ];
					a [ j ] = temp;
					temp = 0;
				}
			}
		}
		for ( int p = 0 ; p < digit ; p++ ) {
			printf ( "%d" , a [ p ] );
		}
		printf ("\n");
	}
	return 0;
}
