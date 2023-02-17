/*逆序输出字符串。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含一个字符串。

输出
对每组数据，逆序输出字符串，并换行。*/

#include <stdio.h>

int main () {
	int n;
	char ch;
	int length;
	char a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		length = 0;
		ch = getchar();
		while ( ch != '\n' ) {
			a [ length ] = ch;
			length++;
			ch = getchar();
		}
		for ( int j = length - 1 ; j >= 0 ; j-- ) {
			printf ( "%c" , a [ j ] );
		}
		printf ("\n");
	}
	return 0;
}
