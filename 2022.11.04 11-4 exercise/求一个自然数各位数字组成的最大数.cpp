/*��һ����Ȼ����λ������ɵ��������

����
��1����һ������N����ʾ�����N�����ݡ�
ÿ�����ݰ���1�� ��Ȼ��num��

���
��ÿ�����ݣ����num��λ������ɵ�������������С�*/

#include <stdio.h>

int main () {
	int n , digit = 0;
	int temp = 0;
	int a [ 100 ] = { 0 };
	char ch;
	scanf ( "%d" , &n );
	getchar();
	for ( int k = 0 ; k < n ; k++ ) {
		digit = 0;
		temp = 0;
		ch = getchar ();
		while ( ch != '\n' ) {
			a [ digit ] = ch - 48;
			digit++;
			ch = getchar ();
		}
		for ( int i = 0 ; i < digit ; i++ ) {
			for ( int j = 0 ; j < digit - i - 1 ; j++ ) {
				if ( a [ j + 1 ] > a [ j ] ) {
					temp = a [ j + 1 ];
					a [ j + 1 ] = a [ j ];
					a [ j ] = temp;
					temp = 0;
				}
			}
		}
		for ( int p = 0 ; p < digit ; p++ ) {
			printf ( "%d" , a [ p ] );
		}
		printf ("\n");
	}
	return 0;
}
