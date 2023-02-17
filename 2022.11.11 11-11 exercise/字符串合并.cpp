/*现有两个字符串，请将两个字符串中的非数字和非字母的字符去掉，并将剩下的字符串合并成一个新的有序（按照ASCII码序升序）字符串，并打印合并后的字符串。
注：输入的每个字符串中不包含换行符、空白符或缩进符

输入
两个字符串。

输出
合并后的字符串。*/

#include <stdio.h>

int main () {
	char a [ 100 ] = { 0 };
	char b [ 100 ] = { 0 };
	int longa = 0 , longb = 0;
	int ch;
	int temp = 0;
	ch = getchar();
	while ( ch != ' ' ) {
		if ( ch <= '9' && ch >= '0' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ) {
			a [ longa ] = ch;
			longa++;
		}
		ch = getchar();
	}
	ch = getchar();
	while ( ch != '\n' ) {
		if ( ch <= '9' && ch >= '0' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ) {
			b [ longb ] = ch;
			longb++;
		}
		ch = getchar();
	}
	for ( int i = 0 ; i < longb ; i++ ) {
		a [ i + longa ] = b [ i ];
	}
	for ( int i = 0 ; i < longa + longb ; i++ ) {
		for ( int j = 0 ; j < longa + longb - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( int i = 0 ; i < longa + longb ; i++ ) {
		printf ( "%c" , a [ i ] );
	}
	return 0;
}
