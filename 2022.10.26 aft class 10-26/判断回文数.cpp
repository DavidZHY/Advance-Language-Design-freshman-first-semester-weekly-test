/*输入一个正整数， 判断它是不是回文数？（回文数是顺着看和倒着看都一样的数，例如1221，12321都是回文数）。

输入
第一行输入一个正整数n，表示有n组数据。每组数据为一个正整数。

输出
对于每组数据，若是回文数，输出“yes”，否则输出“no”*/

#include <stdio.h>

int multip ( int a , int b );
int dig ( int a , int b );

int multip ( int a , int b ) {
	int c = 1;
	for ( int i = 1 ; i <= b ; i++ ) {
		c *= a;
	}
	return c;
}

int dig ( int num , int dig ) {
	int A , tst;
	tst = multip ( 10 , dig );
	A = num / multip ( 10 , dig - 1 ) - num / multip ( 10 , dig ) * 10;
	return A;
}

int main() {
	int ttl , num , n = 0 , i = 1;//ttl:number of numbers ; num:number ; n:number of digits ; i:additional number
	int halfn , decide = 0 , A , B;
	scanf ( "%d" , &ttl );
	for ( int m = 1 ; m <= ttl ; m++ ) {
		scanf ( "%d" , &num );
		while ( num / i != 0 ) {
			n++;
			i *= 10;
		}
		for ( int k = 1 ; k <= n ; k++ ) {
			A = dig ( num , k );
			B = dig ( num , n - k + 1 );
			if ( A != B ) {
				decide++;
			}
		}
		if ( !decide ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}
		decide = 0;
	}
}
