/*判断字符串是否满足要求。如果字符串满足以下要求之一的字符串输出YES，否则输出NO：
字符串等于SCU；
形如xSCUx的字符串,其中x是仅由字母A组成的字符串；

输入
每个测试输入包含1个测试用例。第1行给出一个自然数n (n<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出
每个字符串的检测结果占一行，如果该字符串满足条件，则输出YES，否则输出NO。*/

#include <stdio.h>

#define N 100

int main () {
	int n;
	char ch;
	int length;
	int temp;
	int startp , startA , endA;
	char a [ N ];
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		temp = 0;
		length = 0;
		for ( int i = 0 ; i < N ; i++ ) {
			a [ i ] = '\0';
		}
		ch  = getchar();
		while ( ch != '\n' ) {
			a [ length ] = ch;
			length++;
			ch = getchar();
		}//end input array
		startp = N + 1;
		for ( int i = 0 ; i < length - 2 ; i++ ) {
			if ( a [ i ] == 'S' && a [ i + 1 ] == 'C' && a [ i + 2 ] == 'U' ) {
				startp = i;
				break;
			}
		}//find SCU
		if ( startp == N + 1 ) {
			printf ("NO\n");
			temp = 1;
			continue;
		}//case: no SCU found
		startA = 0;
		endA = 0;
		temp = 0;
		for ( int i = 0 ; i < startp ; i++ ) {
			if ( a [ i ] == 'A' ) {
				startA++;
			} else {
				printf ("NO\n");
				temp = 1;
				break;
			}//not A array
		}//get startA
		if ( temp == 1 ) {
			continue;
		}
		temp = 0;
		for ( int i = startp + 3 ; i < length ; i++ ) {
			if ( a [ i ] == 'A' ) {
				endA++;
			} else {
				printf ("NO\n");
				temp = 1;
				break;
			}//not A array
		}//get endA
		if ( temp == 1 ) {
			continue;
		}
		if ( startA != endA ) {
			printf ("NO\n");
		} else {
			printf ("YES\n");
		}
	}
	return 0;
}
