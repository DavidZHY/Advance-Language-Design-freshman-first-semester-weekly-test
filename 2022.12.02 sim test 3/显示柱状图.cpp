/*根据输入的数字和符号生成相应的柱状图显示。

输入
每个输入包含一个测试用例，第一个整数m，表示随后有m组数据，每组数据由一个数字n和一个字符组成，每组数据之间用空格分隔。数字代表柱状图的高度，字母代表该柱使用的画图符号。如果数字后没有字母，默认该柱的画图符号使用加号+。

输出
每个柱之间用1个空格间隔，图的空白处用空格填充。用减号-表示x轴。正数柱状向上，负数柱状向下。*/

#include <stdio.h>

int main () {
	int a [ 100 ] [ 2 ] = { 0 };
	int b [ 100 ] [ 100 ] = { 0 };
	int n = 0;
	int temp;
	int maxu = 0 , maxd = 0;
	char ch;
	ch = getchar();
	while ( ch != ' ' ) {
		n = n * 10 + ch - 48;
		ch = getchar();
	}//end input column n
	for ( int i = 0 ; i < n ; i++ ) {
		temp = 1;
		ch = getchar();
		if ( ch == ' ' ) {
			ch = getchar();
		}
		if ( ch == '-' ) {
			temp = -1;
			ch = getchar();
		}
		while ( ch >= '0' && ch <= '9' ) {
			a [ i ] [ 0 ] = a [ i ] [ 0 ] * 10 + ch - 48;
			ch = getchar();
		}
		a [ i ] [ 0 ] *= temp;
		if ( ch == ' ' || ch == '\n' ) {
			a [ i ] [ 1 ] = '+';
		} else {
			a [ i ] [ 1 ] = ch;
			ch = getchar();
		}
		if ( temp == 1 ) {
			if ( a [ i ] [ 0 ] > maxu ) {
				maxu = a [ i ] [ 0 ];
			}
		} else {
			if ( a [ i ] [ 0 ] < maxd ) {
				maxd = a [ i ] [ 0 ];
			}
		}
	}//end input content & get max height+(maxu), height-(maxd)
	for ( int i = maxu ; i > 0 ; i-- ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( a [ j ] [ 0 ] >= i ) {
				printf ( "%c" , a [ j ] [ 1 ] );
			} else {
				printf (" ");
			}
			printf (" ");
		}
		printf ("\n");
	}//end print + section
	for ( int i = 0 ; i < 2 * n - 1 ; i++ ) {
		printf ("-");
	}
	printf ("\n");//end print slashes
	for ( int i = -1 ; i >= maxd ; i-- ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( a [ j ] [ 0 ] <= i ) {
				printf ( "%c" , a [ j ] [ 1 ] );
			} else {
				printf (" ");
			}
			printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
