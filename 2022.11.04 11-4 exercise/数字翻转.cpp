/*������������������������������������ת�ĺ��Ƿ�����������ĺ͵ķ�ת������12,34���������������12+34=46,��64=21+43��  

����
������һ����������ʾ��Ҫ�������ݵ����� n��ÿ������������a��b��0<a,b<=10000����

��� 
���������Ŀ��Ҫ�����YES���������NO */

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
