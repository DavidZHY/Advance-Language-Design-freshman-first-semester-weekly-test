/*输入两个正整数m和n，输出m和n的最大公约数。

输入
第1行是一个整数T，表示随后有T组数据。每组数据占一行，包含两个整数，用空格隔开。

输出
对每组数据输出两个整数的最大公约数，并换行。*/

#include <stdio.h>

int main () {
	int n , a , b , max , tst = 1 , i = 1;
	scanf ("%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ("%d %d" , &a , &b );
		while (tst <= a) {
			if ( a % tst == 0 && b % tst == 0 ) {
				max = tst;
			}
			tst++;
		}
		tst = 1;
		printf ("%d\n" , max);
	}
	return 0;
} 
