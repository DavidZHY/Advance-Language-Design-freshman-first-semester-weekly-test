/*����һ���������飬ͳ�Ʋ�ͬ��Ԫ�صĸ�����

����
ÿ������ռһ�У�ÿ�ȸ���������n����30���������n���������Կո�ָ���

���
���ռһ��,�Իس������������ͬ��Ԫ�صĸ�����*/

#include <stdio.h>

int main () {
	int a [ 1001 ] = { 0 };
	int temp , n;
	int count = 0;
	char ch;
	ch = getchar();
	n = ch - 48;
	ch = getchar();
	if ( ch != ' ' ) {
		n = n * 10 + ch - 48;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d" , &temp );
		a [ temp + 501 ]++;
	}
	for ( int i = 0 ; i < 1001 ; i++ ) {
		if ( a [ i ] != 0 ) {
			count++;
		}
	}
	printf ( "%d" , count );
	return 0;
}
