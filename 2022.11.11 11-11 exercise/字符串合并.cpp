/*���������ַ������뽫�����ַ����еķ����ֺͷ���ĸ���ַ�ȥ��������ʣ�µ��ַ����ϲ���һ���µ����򣨰���ASCII���������ַ���������ӡ�ϲ�����ַ�����
ע�������ÿ���ַ����в��������з����հ׷���������

����
�����ַ�����

���
�ϲ�����ַ�����*/

#include <stdio.h>

int main () {
	char a [ 100 ] = { 0 };
	char b [ 100 ] = { 0 };
	int longa = 0 , longb = 0;
	int ch;
	int temp = 0;
	ch = getchar();
	while ( ch != ' ' ) {
		if ( ch <= '9' && ch >= '0' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ) {
			a [ longa ] = ch;
			longa++;
		}
		ch = getchar();
	}
	ch = getchar();
	while ( ch != '\n' ) {
		if ( ch <= '9' && ch >= '0' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ) {
			b [ longb ] = ch;
			longb++;
		}
		ch = getchar();
	}
	for ( int i = 0 ; i < longb ; i++ ) {
		a [ i + longa ] = b [ i ];
	}
	for ( int i = 0 ; i < longa + longb ; i++ ) {
		for ( int j = 0 ; j < longa + longb - i - 1 ; j++ ) {
			if ( a [ j + 1 ] < a [ j ] ) {
				temp = a [ j + 1 ];
				a [ j + 1 ] = a [ j ];
				a [ j ] = temp;
				temp = 0;
			}
		}
	}
	for ( int i = 0 ; i < longa + longb ; i++ ) {
		printf ( "%c" , a [ i ] );
	}
	return 0;
}
