/*给定一个正整数n, (20 ≤n ≤100)n,(20 ≤n ≤100)，求出小于等于nn的所有素数。

输入
第1行是一个整数T，表示随后有T组数据。每组数据占1行，每行有1个整数。

输出
对每组数据输出小于等于nn的所有素数，以空格隔开，并换行。*/

#include <stdio.h>

int prime ( int a );

int prime ( int a ) {
	int i = 2;
	while ( i < a ) {
		if ( a % i == 0 ) {
			return 0;
		}
		i++;
	}
	printf ( "%d " , a );
	return 0;
}

int main () {
	int T , num , count = 2;
	scanf ( "%d" , &T );
	for ( int i = 1 ; i <= T ; i++ ) {
		scanf ( "%d" , &num );
		while ( count <= num ) {
			prime ( count );
			count++;
		}
		count = 2;
		printf ("\n");
	}
	return 0;
}
