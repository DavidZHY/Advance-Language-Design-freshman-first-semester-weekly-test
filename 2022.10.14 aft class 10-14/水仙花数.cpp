/*ˮ�ɻ����й�ʮ������֮һ�����й�����һǧ����������ʷ�����м��ߵĹ����ԡ�������ѧ�ϣ�����Ҳ���֣��������������ġ�ˮ�ɻ�����
����ָһ����λ�������ĸ�λ���ֵ������͵����䱾����д����������ָ����Χ�ڵ�ˮ�ɻ���

����
��1����һ������ TT����ʾ����� TT �����ݡ�ÿ������ռһ�У������������� m,n (100 ��m ��n ��999)m,n (100��m��n��999)

���
��ÿ�����ݣ�Ҫ����� [m,n][m,n]��Χ������ˮ�ɻ������ո��������������������-1��*/

#include <stdio.h>

int blossom ( int num );

int blossom ( int num ) {
	int hun , dix , une , a;
	a = num;
	hun = num / 100;
	num %= 100;
	dix = num / 10;
	num %= 10;
	une = num;
	if ( ( dix * dix * dix + une * une * une + hun * hun * hun ) == a ) {
		return a;
	}
	return 0;
}

int main () {
	int num , une , dix , hun , m , n , count = 0;
	scanf ( "%d" , &num );
	for ( int i = 1 ; i <= num ; i++ ) {
		scanf ( "%d%d" , &m , &n );
		for ( int j = m ; j <= n ; j++) {
			if ( blossom ( j ) == 0 ) {
				
			} else {
				printf ( "%d " , blossom ( j ) );
				count++;
			}
		}
		if ( count ) {
			
		} else {
			printf ("-1");
		}
		printf ("\n");
		count = 0;
	}
	return 0;
}
