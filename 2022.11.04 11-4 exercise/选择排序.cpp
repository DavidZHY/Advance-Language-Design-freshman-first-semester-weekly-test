/*����n��������ʹ��ѡ�������㷨����С��������Ȼ����������

����
һ����1������n����ʾ�����n���������ڶ�����n���������ո������ 

���
��������n-1�У�ÿ��Ϊ����һ�˺�Ľ����*/

#include <stdio.h>

int main () {
	int n;
	int temp;
	int max = 0 , pos;
	int j;
	int a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	for ( int k = 0 ; k < n ; k++ ) {
		scanf ( "%d" , &a [ k ] );
	}
	for ( int t = 0 ; t < n ; t++ ) {
		printf ( "%d " , a [ t ] );
	}
	printf ("\n");
	for ( int i = n - 1 ; i > 1 ; i-- ) {
		max = 0;
		for ( j = 0 ; j < i + 1 ; j++ ) {
			if ( a [ j ] > max ) {
				max = a [ j ];
				pos = j;
			}
		}
		if ( i != pos ) {
			temp = a [ i ];
			a [ i ] = a [ pos ];
			a [ pos ] = temp;
			temp = 0;
		}
		for ( int t = 0 ; t < n ; t++ ) {
			printf ( "%d " , a [ t ] );
		}
		printf ("\n");
	}
	return 0;
}
