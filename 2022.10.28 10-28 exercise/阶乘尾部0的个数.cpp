/*����n�Ľ׳�ĩβ0�ĸ�����

����
��1����һ������N����ʾ�����N�����ݡ�ÿ������ռһ�У�����һ���������ÿո������

���
��ÿ���������n�Ľ׳�ĩβ0�ĸ����������С�*/

#include <stdio.h>

int main () {
	int n , i = 0;
	long result;
	long dig , num;
	long decide = 0;
	long k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	dig = 0;
    	k = 1;
    	decide = 0;
    	scanf ( "%ld" , &num );
    	do {
    		k *= 5;
    		decide = num / k;
    		dig += num / k;
    	} while ( decide != 0 );
    	printf ( "%ld\n" , dig );
    }
	return 0;
}
