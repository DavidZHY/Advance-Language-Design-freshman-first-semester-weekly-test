/*��1+2+��+n��0<=n<=100���ĺ͡�

����
��1������һ������n����ʾ��1�ӵ�n��

���
�����ֿ������(for,while,do...while)����1+2+��+n�ĺͣ�ÿ�ֿ�����������ռһ�С�*/

#include <stdio.h>

int main() {
    int n, i = 1, result = 0;
    scanf("%d", &n);
    for ( i = 1 ; i <= n ; i++ ) {
    	result += i;
    }
    printf ("%d\n" , result);
    result = 0;
    i = 1;
    while ( i <= n ) {
    	result += i;
    	i++;
    }
    printf ("%d\n" , result);
    result = 0;
    i = 1;
    do {
    	result += i;
    	i++;
    } while ( i <= n );
    printf ("%d\n" , result);
    return 0;
}
