/*����N�������������������С��������3������

����
ÿ���������һ��������ݣ�����N+1��������֮���ÿո�ָ��� ��1����������N(1<=N<=100)������N����������Ҫͳ�Ƶ����ݡ�

���
�����������������������ô������������û�������Null��*/

#include <stdio.h>

int main () {
	int a [ 100 ] = { 0 };
	char ch;
	int n = 0;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d" , &a [ i ] );
	}
	int temp = 0;
	for ( int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( int i = 0 ; i < n ; i++ ) {
		if ( a [ i ] % 3 == 0 ) {
			printf ( "%d" , a [ i ] );
			return 0;
		}
	}
	printf ("Null");
	return 0;
}
