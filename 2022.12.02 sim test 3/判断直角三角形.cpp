/*输入三角形的3条边长， 判断三角形是否是直角三角形。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含3个整数代表3条边长(每个整数的平方能够用32位整数表示)，用空格分隔。

输出
每组输出占一行，如果是直角三角形输出Yes，不是则输出No。*/

#include <stdio.h>

int main () {
	int n;
	long long a , b , c;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d%d%d" , &a , &b , &c );
		if ( a == 0 || b == 0 || c == 0 ) {
			printf ("No\n");
		} else if ( a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a ) {
			printf ("Yes\n");
		} else {
			printf ("No\n");
		}
	} 
	return 0;
}
