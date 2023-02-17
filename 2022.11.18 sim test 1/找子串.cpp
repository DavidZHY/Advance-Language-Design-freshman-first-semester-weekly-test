/*请在输入的一段字符串里面查找给定的子串，找到后用注释符号注释起来再输出。子串不区分大小写，即one、One和ONE是同一个子串。另外子串不会重叠出现。

输入
每个输入包含一个测试数据，第一行输入一行待查找的字符串，以回车结束。
第二行输入要查找的子串，以回车结束。字符串最长长度不超过100。

输出
如果找到子串，则在子串前面加注释前标，后面加上注释后标， 把子串(保持原样)注释起来再输出。没有找到就输出原字符串。*/

#include <stdio.h>

int main () {
	char a [ 100 ];
	char b [ 100 ];
	int longa , longb;
	int temp = 0;
	char ch;
	for ( int i = 0 ; i < 100 ; i++ ) {
		a [ i ] = '\0';
	}
	for ( int i = 0 ; i < 100 ; i++ ) {
		b [ i ] = '\0';
	}//end initialize
	ch = getchar();
	for ( longa = 0 ; ch != '\n' ; longa++ ) {
		a [ longa ] = ch;
		ch = getchar();
	}
	ch = getchar();
	for ( longb = 0 ; ch != '\n' ; longb++ ) {
		b [ longb ] = ch;
		ch = getchar();
	}//end input
	for ( int i = 0 ; i < longa ; i++ ) {
		for ( int j = 0 ; j < longb ; j++ ) {
			if ( a [ j + i ] != b [ j ] && a [ j + i ] - b [ j ] != 32 && b [ j ] - a [ j + i ] != 32 ) {
				temp++;
			}
		}
		if ( temp != 0 ) {
			printf ( "%c" , a [ i ] );
		} else {
			printf ("/*");
			for ( int m = i ; m < i + longb ; m++ ) {
				printf ( "%c" , a [ m ] );
			}
			printf ("*/");
			i += longb - 1;
		}
		temp = 0;
	}
	return 0;
}
