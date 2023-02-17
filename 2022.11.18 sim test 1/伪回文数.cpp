/*输入一个正整数， 判断它是不是一个伪回文数。（回文数是顺着看和倒着看都一样的数，例如1221，12321都是回文数，伪回文数是改动一个数字就能变成回文数的数，1位数不是伪回文数）。 

输入
第一行输入一个正整数n，表示下面有n组数据。
每组数据为一个正整数，能够用int保存，占用一行。 

输出
对于每组数据，若是伪回文数，输出“yes”，否则输出“no”*/

#include <stdio.h>

int main () {
	int n;
	char ch;
	int digit , count;
	int a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		count = 0;
		ch = getchar();
		for ( digit = 0 ; ch != '\n' ; digit++ ) {
			a [ digit ] = ch - 48;
			ch = getchar();
		}
		for ( int j = 0 ; j < digit ; j++ ) {
			if ( a [ j ] != a [ digit - j - 1 ] ) {
				count++;
			}
		}
		if ( count == 2 ) {
			printf ("yes\n");
		} else {
			printf ("no\n");
		}
	}
	return 0;
}
