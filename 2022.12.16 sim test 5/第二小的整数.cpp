/*�ҳ����������еڶ�С������

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У���һ������m��1��m��100����ʾ�����m��������

���
��ÿ�����ݣ�����ڶ�С����������ڶ�С���������ڣ������ERROR��*/

#include <stdio.h>

int main () {
	int l;
	int a [ 100 ];
	int n;
	int temp;
	int min;
	scanf ( "%d" , &l );
	for ( int k = 0 ; k < l ; k++ ) {
		scanf ( "%d" , &n );
		for ( int i = 0 ; i < n ; i++ ) {
			scanf ( "%d" , &a [ i ] );
		}//end entering array
		for ( int i = 0 ; i < n ; i++ ) {
			for ( int j = 0 ; j < n - i - 1 ; j++ ) {
				if ( a [ j ] > a [ j + 1 ] ) {
					temp = a [ j ];
					a [ j ] = a [ j + 1 ];
					a [ j + 1 ] = temp;
				}
			}
		}//end requeuing
		min = a [ 0 ];
		temp = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			if ( a [ i ] > min ) {
				printf ( "%d\n" , a [ i ] );
				temp++;
				break;
			}
		}
		if ( !temp ) {
			printf ("ERROR\n");
		}
	}
	return 0;
}
