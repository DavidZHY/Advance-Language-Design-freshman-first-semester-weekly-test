/*��������������m��n�����m��n�����Լ����

����
��1����һ������T����ʾ�����T�����ݡ�ÿ������ռһ�У����������������ÿո������

���
��ÿ����������������������Լ���������С�*/

#include <stdio.h>

int main () {
	int n , a , b , max , tst = 1 , i = 1;
	scanf ("%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ("%d %d" , &a , &b );
		while (tst <= a) {
			if ( a % tst == 0 && b % tst == 0 ) {
				max = tst;
			}
			tst++;
		}
		tst = 1;
		printf ("%d\n" , max);
	}
	return 0;
} 
