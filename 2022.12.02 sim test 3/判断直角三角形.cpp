/*���������ε�3���߳��� �ж��������Ƿ���ֱ�������Ρ�

����
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����3����������3���߳�(ÿ��������ƽ���ܹ���32λ������ʾ)���ÿո�ָ���

���
ÿ�����ռһ�У������ֱ�����������Yes�����������No��*/

#include <stdio.h>

int main () {
	int n;
	long long a , b , c;
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) {
		scanf ( "%d%d%d" , &a , &b , &c );
		if ( a == 0 || b == 0 || c == 0 ) {
			printf ("No\n");
		} else if ( a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a ) {
			printf ("Yes\n");
		} else {
			printf ("No\n");
		}
	} 
	return 0;
}
