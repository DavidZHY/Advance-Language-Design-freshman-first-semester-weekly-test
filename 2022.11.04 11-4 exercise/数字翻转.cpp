/*现在有任意两个正整数，问它们两个数翻转的和是否等于两个数的和的翻转。比如12,34便满足该条件，即12+34=46,而64=21+43。  

输入
先输入一个正整数表示将要测试数据的组数 n。每行两个正整数a和b（0<a,b<=10000）。

输出 
如果满足题目的要求输出YES，否则输出NO */

#include <stdio.h>

int time10 ( int a );
int time10 ( int a ) {
	int A = 1;
	for ( int i = 0 ; i < a ; i++ ) {
		A *= 10;
	}
	return A;
}

int main () {
	int n;
	int i , j;
	int invert = 1 , temp;
	int a [ 5 ] = { 0 };
	int b [ 5 ] = { 0 };
	int diga = 0 , digb = 0 , digitinvres = 0;
	int aa , invertaa = 0 , bb , invertbb = 0;
	int result , invertresult , result1 = 0;
	scanf ( "%d" , &n );
	for ( i = 0 ; i < n ; i++ ) {
		diga = 0;
		digb = 0;
		digitinvres = 0;
		invertaa = 0;
		invertbb = 0;
		result1 = 0;
		fflush (stdin);
		scanf ( "%d%d" , &aa , &bb );
		result = aa + bb;
		temp = aa;
		while ( temp != 0 ) {
			temp /= 10;
			diga++;
		}
		temp = bb;
		while ( temp != 0 ) {
			temp /= 10;
			digb++;
		}
		for ( j = 1 ; j <= diga ; j++ ) {
			invert = time10 ( j - 1 );
			temp = aa / invert - ( aa / ( 10 * invert ) ) * 10;
			invertaa += temp * time10 ( diga - j );
		}
		for ( j = 1 ; j <= digb ; j++ ) {
			invert = time10 ( j - 1 );
			temp = bb / invert - ( bb / ( 10 * invert ) ) * 10;
			invertbb += temp * time10 ( digb - j );
		}
		invertresult = invertaa + invertbb;
		temp = invertresult;
		while ( temp != 0 ) {
			temp /= 10;
			digitinvres++;
		}
		for ( j = 1 ; j <= digitinvres ; j++ ) {
			invert = time10 ( j - 1 );
			temp = invertresult / invert - ( invertresult / ( 10 * invert ) ) * 10;
			result1 += temp * time10 ( digitinvres - j );
		}
		if ( result == result1 ) {
			printf ("YES\n");
		} else {
			printf ("NO\n");
		}
	}
	return 0;
}
