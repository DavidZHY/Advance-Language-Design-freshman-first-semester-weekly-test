/*�κδ���6��ż�������Էֽ�������������ĺ͡�����n��������н⣬��С����ǰ������ں��������Ҫ�ظ���

����
ÿ���������һ����������������һ������(�ܹ���32λ������ʾ)��

���
�Է���Ҫ����������ݣ�����������н⣬ÿ����ռһ�У��������ÿո�ָ��������벻����Ҫ������������ERROR��*/

#include <stdio.h>

int prime ( long long n );

int prime ( long long n ) {
	for ( long long i = 2 ; i * i <= n ; i++ ) {
		if ( n % i == 0 ) {
			return 0;
		}
	}
	return 1;
}

int main () {
	long long num;
	scanf ( "%lld" , &num );
	if ( num <= 6 || num % 2 != 0 ) {
		printf ("ERROR");
		return 0;
	}
	for ( long long i = 2 ; i * 2 <= num ; i++ ) {
		if ( prime ( i ) && prime ( num - i ) ) {
			printf ( "%lld %lld" , i , num - i );
			printf ("\n");
		}
	}
	return 0;
}
