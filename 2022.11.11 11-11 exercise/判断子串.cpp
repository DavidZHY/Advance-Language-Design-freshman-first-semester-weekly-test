/*�ж�һ���ַ����Ƿ�����һ���ַ������Ӵ�������ʾ����һ���ַ���Ϊabcdefg����abc��defg��Ϊ���Ӵ�����acd��edg���������Ӵ���

����
�������ַ���a���������ַ���b��  

���
�ж��ַ���b�Ƿ����ַ���a���Ӵ�����b��a���Ӵ������YES���������NO��*/

#include <stdio.h>

int main () {
	char a [ 100 ] = { 0 };
	char b [ 100 ] = { 0 };
	int longa = 0 , longb = 0;
	int ch;
	int temp = 0;
	ch = getchar();
	while ( ch != '\n' ) {
		a [ longa ] = ch;
		longa++;
		ch = getchar();
	}
	ch = getchar();
	while ( ch != '\n' ) {
		b [ longb ] = ch;
		longb++;
		ch = getchar();
	}
	for ( int i = 0 ; i < longa - longb + 1 ; i++ ) {
		for ( int j = 0 ; j < longb ; j++ ) {
			if ( a [ j + i ] != b [ j ] ) {
				temp++;
			}
		}
		if ( !temp ) {
			printf ("YES");
			return 0;
		}
		temp = 0;
	}
	printf ("NO");
	return 0;
}
