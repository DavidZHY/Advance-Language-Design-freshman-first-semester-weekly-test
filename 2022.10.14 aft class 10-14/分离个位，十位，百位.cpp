/*��һ����λ�������ĸ�λ��ʮλ����λ���뿪���ֱ��������

����
��1����һ������n����ʾ�����n�����ݡ�
ÿ������ռһ�У�����һ��������

���
����������������λ�����������ո�λ��ʮλ����λ��˳�������λ���֣��м��ö��Ÿ�������������ַ�����illegal����*/

#include <stdio.h>

int main () {
	int num , une , dix , hun , n;
	scanf ( "%d" , &n );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &num );
		if ( num < 100 || num > 999  ) {
			printf ("illegal\n");
		} else {
			hun = num / 100;
			num %= 100;
			dix = num / 10;
			num %= 10;
			une = num;
			printf ( "%d,%d,%d\n" , une , dix , hun );
		}
	}
	return 0;
}
