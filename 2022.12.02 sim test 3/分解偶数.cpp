/*任何大于6的偶数都可以分解成两个奇质数的和。输入n，输出所有解，按小的在前，大的在后输出，不要重复。

输入
每行输入包含一个测试用例，输入一个整数(能够用32位整数表示)。

输出
对符合要求的输入数据，依次输出所有解，每个解占一行，两个数用空格分隔。对输入不符合要求的数，则输出ERROR。*/

#include <stdio.h>

int prime ( long long n );

int prime ( long long n ) {
	for ( long long i = 2 ; i * i <= n ; i++ ) {
		if ( n % i == 0 ) {
			return 0;
		}
	}
	return 1;
}

int main () {
	long long num;
	scanf ( "%lld" , &num );
	if ( num <= 6 || num % 2 != 0 ) {
		printf ("ERROR");
		return 0;
	}
	for ( long long i = 2 ; i * 2 <= num ; i++ ) {
		if ( prime ( i ) && prime ( num - i ) ) {
			printf ( "%lld %lld" , i , num - i );
			printf ("\n");
		}
	}
	return 0;
}
