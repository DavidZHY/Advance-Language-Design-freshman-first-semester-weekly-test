/*������������ֺͷ���������Ӧ����״ͼ��ʾ��

����
ÿ���������һ��������������һ������m����ʾ�����m�����ݣ�ÿ��������һ������n��һ���ַ���ɣ�ÿ������֮���ÿո�ָ������ִ�����״ͼ�ĸ߶ȣ���ĸ�������ʹ�õĻ�ͼ���š�������ֺ�û����ĸ��Ĭ�ϸ����Ļ�ͼ����ʹ�üӺ�+��

���
ÿ����֮����1���ո�����ͼ�Ŀհ״��ÿո���䡣�ü���-��ʾx�ᡣ������״���ϣ�������״���¡�*/

#include <stdio.h>

int main () {
	int a [ 100 ] [ 2 ] = { 0 };
	int b [ 100 ] [ 100 ] = { 0 };
	int n = 0;
	int temp;
	int maxu = 0 , maxd = 0;
	char ch;
	ch = getchar();
	while ( ch != ' ' ) {
		n = n * 10 + ch - 48;
		ch = getchar();
	}//end input column n
	for ( int i = 0 ; i < n ; i++ ) {
		temp = 1;
		ch = getchar();
		if ( ch == ' ' ) {
			ch = getchar();
		}
		if ( ch == '-' ) {
			temp = -1;
			ch = getchar();
		}
		while ( ch >= '0' && ch <= '9' ) {
			a [ i ] [ 0 ] = a [ i ] [ 0 ] * 10 + ch - 48;
			ch = getchar();
		}
		a [ i ] [ 0 ] *= temp;
		if ( ch == ' ' || ch == '\n' ) {
			a [ i ] [ 1 ] = '+';
		} else {
			a [ i ] [ 1 ] = ch;
			ch = getchar();
		}
		if ( temp == 1 ) {
			if ( a [ i ] [ 0 ] > maxu ) {
				maxu = a [ i ] [ 0 ];
			}
		} else {
			if ( a [ i ] [ 0 ] < maxd ) {
				maxd = a [ i ] [ 0 ];
			}
		}
	}//end input content & get max height+(maxu), height-(maxd)
	for ( int i = maxu ; i > 0 ; i-- ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( a [ j ] [ 0 ] >= i ) {
				printf ( "%c" , a [ j ] [ 1 ] );
			} else {
				printf (" ");
			}
			printf (" ");
		}
		printf ("\n");
	}//end print + section
	for ( int i = 0 ; i < 2 * n - 1 ; i++ ) {
		printf ("-");
	}
	printf ("\n");//end print slashes
	for ( int i = -1 ; i >= maxd ; i-- ) {
		for ( int j = 0 ; j < n ; j++ ) {
			if ( a [ j ] [ 0 ] <= i ) {
				printf ( "%c" , a [ j ] [ 1 ] );
			} else {
				printf (" ");
			}
			printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
