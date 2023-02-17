/*水仙花是中国十大名花之一，在中国已有一千多年栽培历史，具有极高的观赏性。而在数学上，我们也发现，具有这样的美的“水仙花数”
它是指一个三位数，它的各位数字的立方和等于其本身。编写程序计算输出指定范围内的水仙花数

输入
第1行是一个整数 TT，表示随后有 TT 组数据。每组数据占一行，包含两个整数 m,n (100 ≤m ≤n ≤999)m,n (100≤m≤n≤999)

输出
对每组数据，要求输出 [m,n][m,n]范围的所有水仙花数，空格隔开，如果不存在则输出-1。*/

#include <stdio.h>

int blossom ( int num );

int blossom ( int num ) {
	int hun , dix , une , a;
	a = num;
	hun = num / 100;
	num %= 100;
	dix = num / 10;
	num %= 10;
	une = num;
	if ( ( dix * dix * dix + une * une * une + hun * hun * hun ) == a ) {
		return a;
	}
	return 0;
}

int main () {
	int num , une , dix , hun , m , n , count = 0;
	scanf ( "%d" , &num );
	for ( int i = 1 ; i <= num ; i++ ) {
		scanf ( "%d%d" , &m , &n );
		for ( int j = m ; j <= n ; j++) {
			if ( blossom ( j ) == 0 ) {
				
			} else {
				printf ( "%d " , blossom ( j ) );
				count++;
			}
		}
		if ( count ) {
			
		} else {
			printf ("-1");
		}
		printf ("\n");
		count = 0;
	}
	return 0;
}
