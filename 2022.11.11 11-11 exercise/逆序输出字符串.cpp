/*��������ַ�����

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����һ���ַ�����

���
��ÿ�����ݣ���������ַ����������С�*/

#include <stdio.h>

int main () {
	int n;
	char ch;
	int length;
	char a [ 100 ] = { 0 };
	scanf ( "%d" , &n );
	getchar();
	for ( int i = 0 ; i < n ; i++ ) {
		length = 0;
		ch = getchar();
		while ( ch != '\n' ) {
			a [ length ] = ch;
			length++;
			ch = getchar();
		}
		for ( int j = length - 1 ; j >= 0 ; j-- ) {
			printf ( "%c" , a [ j ] );
		}
		printf ("\n");
	}
	return 0;
}
