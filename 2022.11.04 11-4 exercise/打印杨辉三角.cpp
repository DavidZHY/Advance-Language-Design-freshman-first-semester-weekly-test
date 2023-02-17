/*杨辉三角形规律如下：（前提：顶端的数为1）.
1、每个数等于它上方两数之和。（比如第5行第二个数等于第四行第一数与第四行第二数之和，第9行第7个数等于第八行第6个数与第八行第7个数之和）
2、每行数字左右对称，由1开始逐渐变大。
3、第n行的数字有n项。

输入
第1行是一个整数N，表示随后有N组数据。
每组数据包含1个数num。

输出
对每组数据，输出前num行杨辉三角形，同一行的元素以空格隔开。*/

#include <stdio.h>

int main () {
	int n;
	int line;
	int a [ 100 ] = { 0 };
	int b [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	fflush (stdin);
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < 100 ; j++ ) {
			a [ j ] = 0;
			b [ j ] = 0;
		}
		a [ 0 ] = 1;
		scanf ( "%d" , &line );
		for ( int j = 1 ; j < line + 1 ; j++ ) {
			for ( int k = 0 ; k < j ; k++ ) {
				printf ( "%d " , a [ k ] );
			}
			printf ("\n");
			b [ 0 ] = 1;
			for ( int m = 1 ; m < line + 1 ; m++ ) {
				b [ m ] = a [ m ] + a [ m -1 ];
			}
			for ( int p = 0 ; p < line + 1 ; p++ ) {
				a [ p ] = b [ p ];
			}
		}
	}
	return 0;
}
