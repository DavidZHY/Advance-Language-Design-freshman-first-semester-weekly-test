/*����һ��������n, (20 ��n ��100)n,(20 ��n ��100)�����С�ڵ���nn������������

����
��1����һ������T����ʾ�����T�����ݡ�ÿ������ռ1�У�ÿ����1��������

���
��ÿ���������С�ڵ���nn�������������Կո�����������С�*/

#include <stdio.h>

int prime ( int a );

int prime ( int a ) {
	int i = 2;
	while ( i < a ) {
		if ( a % i == 0 ) {
			return 0;
		}
		i++;
	}
	printf ( "%d " , a );
	return 0;
}

int main () {
	int T , num , count = 2;
	scanf ( "%d" , &T );
	for ( int i = 1 ; i <= T ; i++ ) {
		scanf ( "%d" , &num );
		while ( count <= num ) {
			prime ( count );
			count++;
		}
		count = 2;
		printf ("\n");
	}
	return 0;
}
