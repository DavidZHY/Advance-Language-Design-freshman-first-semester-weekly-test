/*����һ������A[N]��N<=100���У���K(1>=K && K <=N)С������

����
��1����һ������N����ʾ����A�Ĵ�С��Ȼ�����һ������K��1>=K && K <=N����������N����������ʾ����A��ÿһ��Ԫ�ء�ע�⣺����Ԫ��������ģ�����������Ԫ�ز���ȣ�����

���
�������A�е�KС��Ԫ��*/

#include <stdio.h>

int main() {
	int a [ 100 ] = { 0 };
	int temp = 0;
    int n, i, k;
    scanf("%d%d", &n,&k);
    if ( k > n || k < 1 ) {
    	return 0;
    }
    for (i = 0; i < n ; i++) {
        scanf( "%d", &a [ i ] );
    }
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
	printf ( "%d" , a [ k - 1 ] );
    return 0;
}
