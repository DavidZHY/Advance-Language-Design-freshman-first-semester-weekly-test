/*给定一个整型数组，统计不同的元素的个数。

输入
每组输入占一行，每先给出正整数n（≤30），随后是n个整数，以空格分隔。

输出
输出占一行,以回车结束。输出不同的元素的个数。*/

#include <stdio.h>

int main () {
	int a [ 1001 ] = { 0 };
	int temp , n;
	int count = 0;
	char ch;
	ch = getchar();
	n = ch - 48;
	ch = getchar();
	if ( ch != ' ' ) {
		n = n * 10 + ch - 48;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d" , &temp );
		a [ temp + 501 ]++;
	}
	for ( int i = 0 ; i < 1001 ; i++ ) {
		if ( a [ i ] != 0 ) {
			count++;
		}
	}
	printf ( "%d" , count );
	return 0;
}
