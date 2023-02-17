/*判断一个字符串是否是另一个字符串的子串。（提示：若一个字符串为abcdefg，则abc、defg均为其子串，而acd，edg均不是其子串）

输入
先输入字符串a，再输入字符串b。  

输出
判断字符串b是否是字符串a的子串。若b是a的子串，输出YES；否则输出NO。*/

#include <stdio.h>

int main () {
	char a [ 100 ] = { 0 };
	char b [ 100 ] = { 0 };
	int longa = 0 , longb = 0;
	int ch;
	int temp = 0;
	ch = getchar();
	while ( ch != '\n' ) {
		a [ longa ] = ch;
		longa++;
		ch = getchar();
	}
	ch = getchar();
	while ( ch != '\n' ) {
		b [ longb ] = ch;
		longb++;
		ch = getchar();
	}
	for ( int i = 0 ; i < longa - longb + 1 ; i++ ) {
		for ( int j = 0 ; j < longb ; j++ ) {
			if ( a [ j + i ] != b [ j ] ) {
				temp++;
			}
		}
		if ( !temp ) {
			printf ("YES");
			return 0;
		}
		temp = 0;
	}
	printf ("NO");
	return 0;
}
