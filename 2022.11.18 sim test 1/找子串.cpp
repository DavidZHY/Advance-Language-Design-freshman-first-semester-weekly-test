/*���������һ���ַ���������Ҹ������Ӵ����ҵ�����ע�ͷ���ע��������������Ӵ������ִ�Сд����one��One��ONE��ͬһ���Ӵ��������Ӵ������ص����֡�

����
ÿ���������һ���������ݣ���һ������һ�д����ҵ��ַ������Իس�������
�ڶ�������Ҫ���ҵ��Ӵ����Իس��������ַ�������Ȳ�����100��

���
����ҵ��Ӵ��������Ӵ�ǰ���ע��ǰ�꣬�������ע�ͺ�꣬ ���Ӵ�(����ԭ��)ע�������������û���ҵ������ԭ�ַ�����*/

#include <stdio.h>

int main () {
	char a [ 100 ];
	char b [ 100 ];
	int longa , longb;
	int temp = 0;
	char ch;
	for ( int i = 0 ; i < 100 ; i++ ) {
		a [ i ] = '\0';
	}
	for ( int i = 0 ; i < 100 ; i++ ) {
		b [ i ] = '\0';
	}//end initialize
	ch = getchar();
	for ( longa = 0 ; ch != '\n' ; longa++ ) {
		a [ longa ] = ch;
		ch = getchar();
	}
	ch = getchar();
	for ( longb = 0 ; ch != '\n' ; longb++ ) {
		b [ longb ] = ch;
		ch = getchar();
	}//end input
	for ( int i = 0 ; i < longa ; i++ ) {
		for ( int j = 0 ; j < longb ; j++ ) {
			if ( a [ j + i ] != b [ j ] && a [ j + i ] - b [ j ] != 32 && b [ j ] - a [ j + i ] != 32 ) {
				temp++;
			}
		}
		if ( temp != 0 ) {
			printf ( "%c" , a [ i ] );
		} else {
			printf ("/*");
			for ( int m = i ; m < i + longb ; m++ ) {
				printf ( "%c" , a [ m ] );
			}
			printf ("*/");
			i += longb - 1;
		}
		temp = 0;
	}
	return 0;
}
